/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:52:01 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/05 10:17:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP

#include <memory>
#include <iostream>
#include <algorithm>
#include <exception>
#include "../iterators/iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../type_traits/type_traits.hpp"
#include "../algorithm/algorithm.hpp"

namespace ft
{

	//+------------------------------------------------------------------------+
	//|                               Vector                                   |
	//+------------------------------------------------------------------------+
	template<class _Tp, class _Allocator = std::allocator<_Tp> > 

	class vector
	{
		//+--------------------------------------------------------------------+
		//|                         [ Member types ]                           |
		//+--------------------------------------------------------------------+

	public:
		typedef _Tp     	                                	value_type;
		typedef	_Allocator										allocator_type;
		typedef typename allocator_type::pointer            	pointer;
		typedef typename allocator_type::const_pointer      	const_pointer;
		typedef typename allocator_type::reference		    	reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::size_type          	size_type;
		typedef typename allocator_type::difference_type    	difference_type;
		typedef	ft::base_Iterator<pointer>						iterator;
		typedef	ft::base_Iterator<const_pointer>				const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
    	typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
	private:
		pointer                                         		__begin_;
		pointer                                         		__end_;
		pointer                                         		__end_cap_; //end of the allocated memory
		allocator_type											__alloc;

		//+--------------------------------------------------------------------+
		//|                           [ Exceptions ]                           |
		//+--------------------------------------------------------------------+
		void __throw_length_error() const
		{
			throw std::length_error("vector");
		}
		void __throw_out_of_range() const
		{
			throw std::out_of_range("vector");
		}
		void __throw_is_empty() const
		{
			throw "vector is empty";
		}
	public:
		//+--------------------------------------------------------------------+
		//|                          [ Constracors ]                           |
		//+--------------------------------------------------------------------+
		/* Empty container constructor (default constructor) */
		explicit vector (const allocator_type &alloc = allocator_type())
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(alloc)
		{
			// std::cout << "Empty container\n";
		}
		
		/* Fill constructor */
		explicit vector (size_type __n, const value_type &__val = value_type(), const allocator_type &alloc = allocator_type())
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(alloc)
		{
			// std::cout << "Fill container\n";
			if (__n > 0)
			{
				/* Vector Allocation with size of (__n), and assign it to __begin_ */
				if (__n > __alloc.max_size())
					__throw_length_error();
				__begin_ = __end_ = __alloc.allocate(__n);
				__end_cap_ = __begin_ + __n;

				/* Constraction at end */
				while (__n-- > 0)
					__alloc.construct(__end_++, __val);
			}	
		}

		/* Range constructor */
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(alloc)
		{
			for (; first != last; ++first)
        		push_back_no_recommend(*first);
		}

		/* Copy constructor */
		vector(const vector &__x)
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(__x.__alloc)
		{
			// std::cout << "copy container\n";
			pointer	__begin_origine = __x.__begin_;
			size_type __n = __x.size();
			if (__n > 0)
			{
				/* Vector Allocation with size of (__n), and assign it to __begin_ */
				if (__n > __alloc.max_size())
					__throw_length_error();
				__begin_ = __alloc.allocate(__n);
				__end_ = __begin_;
				__end_cap_ = __begin_ + __n;

				/* Constraction at end */
				for (size_type i = 0; i < __n ; i++)
					__alloc.construct(__end_++, *__begin_origine++);			
			}
		}

		vector &operator = (const vector &__x)
		{
			if (this != &__x)
            	assign(__x.__begin_, __x.__end_);
       		return (*this);
		}

		~vector ()
		{
			// std::cout << "destrctor container\n";
			/* destruct */
			while (__end_ != __begin_)
				__alloc.destroy(--__end_);

			/* deallocate */
			__alloc.deallocate(__begin_, capacity());
		}

		//+--------------------------------------------------------------------+
		//|    	              [ iterator / const_iterator ]                    |
		//+--------------------------------------------------------------------+		
		iterator begin()  
		{return iterator(__begin_);}

		iterator end() 
		{return iterator(__end_);}

		const_iterator begin() const
		{return const_iterator(__begin_);}

		const_iterator end() const
		{return const_iterator(__end_);}

		reverse_iterator rbegin() 
		{return reverse_iterator(__end_);}
	
		reverse_iterator rend() 
		{return reverse_iterator(__begin_);}

		const_reverse_iterator rbegin() const
		{return const_reverse_iterator(__end_);}

		const_reverse_iterator rend() const
		{return const_reverse_iterator(__begin_);}

		//+--------------------------------------------------------------------+
		//|    	                       [ Capacity ]                     	   |
		//+--------------------------------------------------------------------+
		size_type size() const
		{ return static_cast<size_type>(__end_ - __begin_); }

		size_type capacity() const
		{ return static_cast<size_type>(__end_cap_ - __begin_); }

		bool empty() const
		{ return __begin_ == __end_; }

		size_type max_size() const
		{
			return std::min<size_type>(
				__alloc.max_size(), 
				std::numeric_limits<difference_type>::max() // PRTDIFF_MAX
			);
		}

		void reserve(size_type __n)
		{
			if (__n > max_size())
				__throw_length_error();
			if (__n > capacity())
			{
				__split_buffer __v(__n, size(), __alloc);
				__construct_backward_and_swap_(__v);
			}	//	~__split_buffer() => destroy the old vector
		}

		void resize (size_type __n, const_reference __val = value_type()) // exemple value_type() = int() = 0
		{
			size_type __current_size = size();
			if (__current_size < __n)
			{
				/* Append */
				__append(__n - __current_size, __val);
			}
			else if (__current_size > __n)
			{
				/* Destruct At End */
				__destruct_at_end(__begin_ + __n);
			}
		}

		//+--------------------------------------------------------------------+
		//|    	                       [ Modifiers ]						    |
		//+--------------------------------------------------------------------+
		//------------------------------------------------------------ [ clear ]
		void clear()
		{ __destruct_at_end(__begin_); }

		//----------------------------------------------------------- [ insert ]
		iterator insert (iterator __position, const_reference __val)
		{
			pointer __p = __begin_ + (__position - begin());
			if (__end_ < __end_cap_)
			{
				if (__p == __end_)
					__alloc.construct(__end_++, __val);
				else
				{
					__shift_right(__p, __end_, __p + 1);
					const_pointer __pointer_ = &__val;
					// check if __val is a reference to some element of this vector
					if (__p <= __pointer_ && __pointer_ < __end_)
						++__pointer_;
					*__p = *__pointer_;
				}
			}
			else
			{
				__split_buffer __v(__recommend(size() + 1), __p - __begin_, __alloc);
				__v.vec.push_back(__val);
				__p = __construct_backward_and_swap_(__v, __p);
			}
			return __make_iter(__p);
		}

		iterator insert(iterator __position, size_type __n, const_reference __val)
		{
			pointer __p = __begin_ + (__position - begin());
			if (__n > 0)
			{
				if (__n <= static_cast<size_type>(__end_cap_ - __end_))
				{
					size_type __old_n = __n;
					pointer __old_last = __end_;
					if (__n > static_cast<size_type>(__end_ - __p))
					{
						size_type __diff = __n - (__end_ - __p);
						__construct_at_end(__diff, __val);
						__n -= __diff;
					}
					if (__n > 0)
					{
						__shift_right(__p, __old_last, __p + __old_n);
						const_pointer __pointer_ = &__val;
						if (__p <= __pointer_ && __pointer_ < __end_)
							__pointer_ += __old_n;
						pointer __p_h = __p;
						while (__n--)
							*__p_h++ = *__pointer_;
					}
				}
				else
				{
					__split_buffer __v(__recommend(size() + __n), __p - __begin_, __alloc);
					__v.vec.__construct_at_end(__n, __val);
					__p = __construct_backward_and_swap_(__v, __p);
				}
			}
			return __make_iter(__p);
		}

		template <class InputIterator>
		iterator insert (iterator __position, InputIterator __first, InputIterator __last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			size_type __n = __position - begin();
			size_type __size = std::distance(__first, __last);
			pointer __p = __begin_ + __n;
			if (__size > 0)
			{
				if (__size <= static_cast<size_type>(__end_cap_ - __end_))
				{
					iterator __it = __make_iter(__p);
					while (__first != __last)
						insert(__it++, *__first++);
				}
				else
				{
					pointer __ptr = __begin_;
					__split_buffer __v(__recommend(size() + __size), 0, __alloc);
					while (__ptr != __p)
						__v.vec.__alloc.construct(__v.vec.__end_++, *__ptr++);
					while (__first != __last)
						__v.vec.__alloc.construct(__v.vec.__end_++, *__first++);
					while (__ptr != __end_)
						__v.vec.__alloc.construct(__v.vec.__end_++, *__ptr++);
					swap(__v.vec);
					__p = __begin_ + __n;
				}
			}
			return __make_iter(__p);
		}

		//------------------------------------------------------------ [ erase ]
		iterator erase(iterator __position)
		{
			if (__position != end())
			{
				pointer __p = __begin_ + (__position - begin());
				pointer __first = __p + 1;
				pointer __last = __end_;
				for (; __first != __last; ++__first, ++__p)
					*__p = *__first;
				__alloc.destroy(--__end_);
			}
			return __position;
		}

		iterator erase(iterator __first, iterator __last)
		{
			pointer __f = __begin_ + (__first - begin());
			pointer __l = __begin_ + (__last - begin());
			if (__f != __l)
			{
				for (;__l != __end_; __l++, __f++)
					*__f = *__l;
				while (__end_ != __f)
					__alloc.destroy(--__end_);
			}
			return __first;
		}

		//-------------------------------------------------------- [ puch_back ]
	private:
		void push_back_no_recommend(const_reference __x)
		{
			if (__end_ != __end_cap_)
				__alloc.construct(__end_++, __x);
			else
			{
				__split_buffer __v(size() + 1, size(), __alloc);
				__v.vec.__alloc.construct(__v.vec.__end_++, __x);
				__construct_backward_and_swap_(__v);
			}
		}
	public:
		void push_back(const_reference __x)
		{
			if (__end_ != __end_cap_)
				__alloc.construct(__end_++, __x);
			else
			{
				__split_buffer __v(__recommend(size() + 1), size(), __alloc);
				__v.vec.__alloc.construct(__v.vec.__end_++, __x);
				__construct_backward_and_swap_(__v);
			}
		}

		//--------------------------------------------------------- [ pop_back ]
		void pop_back()
		{
			if (!empty())
				__alloc.destroy(--__end_);
		}

		//------------------------------------------------------------- [ swap ]
		void swap (vector &__x)
		{
			std::swap(__begin_, __x.__begin_);
			std::swap(__end_, __x.__end_);
			std::swap(__end_cap_, __x.__end_cap_);
		}

		//----------------------------------------------------------- [ assing ]
		void assign (size_type __n, const_reference __val)
		{
			if (__n <= capacity())
			{
				size_type __size = size();
				std::fill_n(__begin_, std::min(__n, __size), __val);
				if (__n > __size)
					__construct_at_end(__n - __size, __val);
				else
					__destruct_at_end(__begin_ + __n);
			}
			else
			{
				/* Destroy */
				clear();
				
				/* Deallocate*/
				__alloc.deallocate(__begin_, capacity());
				__begin_ = __end_ = __end_cap_ = nullptr;
				
				/* Allocate*/ 
				size_type __s = __recommend(__n);
				if (__s > max_size())
					__throw_length_error();
				__begin_ = __end_ = __alloc.allocate(__s);
				__end_cap_ = __begin_ + __s;

				/* Construct*/ 
				__construct_at_end(__n, __val);
			}
		}

		template <class InputIterator> 
		void assign (InputIterator __first, InputIterator __last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		{
			clear();
			size_type __n = std::distance(__first, __last);
			if (capacity() < __n)
			{
				__split_buffer __v(__n, 0, __alloc);
				swap(__v.vec);
			}
			while (__first != __last)
				__alloc.construct(__end_++, *__first++);
		}
		//+--------------------------------------------------------------------+
		//|    	                    [ Element access ]                         |
		//+--------------------------------------------------------------------+
		// operator[]
		// at
		//------------------------------------------------------------ [ front ]
		reference front()
		{
			if(empty())
				__throw_is_empty();
			return *__begin_;
		}

		const_reference front() const
		{
			if(empty())
				__throw_is_empty();
			return *__begin_;
		}

		//------------------------------------------------------------- [ back ]
		reference back()
		{
			if(empty())
				__throw_is_empty();
			return *(__end_ - 1);
		}

		const_reference back() const
		{
			if(empty())
				__throw_is_empty();
			return *(__end_ - 1);
		}
		
		//------------------------------------------------------------- [ data ]
		value_type* data() throw()
		{
			return __begin_;
		}
		
		const value_type* data() const throw()
		{
			return __begin_;
		}

		//--------------------------------------------------------------- [ at ]
		reference at (size_type n)
		{
			if (n >= size() || n < 0)
				__throw_out_of_range();
			return *(__begin_ + n);
		}

		const_reference at (size_type n) const
		{
			if (n >= size() || n < 0)
				__throw_out_of_range();
			return *(__begin_ + n);
		}

		//---------------------------------------------------------- operator []
		reference operator [] (size_type n)
		{ return *(__begin_ + n); }

		const_reference operator [] (size_type n) const
		{ return *(__begin_ + n); }
		//+--------------------------------------------------------------------+
		//|    	                       [ Allocator ]                           |
		//+--------------------------------------------------------------------+
		//---------------------------------------------------- [ get_allocator ]
		allocator_type get_allocator() const
		{ return __alloc; }

	private:
		//+--------------------------------------------------------------------+
		//|                             [ Tools ]                              |
		//+--------------------------------------------------------------------+
		struct __split_buffer
		{
			vector<value_type, allocator_type> vec;
			__split_buffer(size_type __cap, size_type __size, allocator_type &alloc) : vec(alloc)
			{
				pointer __new;
				__new = (__cap != 0) ? vec.__alloc.allocate(__cap) : nullptr;
				vec.__begin_ = vec.__end_ = __new + __size;
				vec.__end_cap_ = __new + __cap;
			}
			~__split_buffer()
			{
				// std::cout << "old vector destrected \n";
			}
		};

		pointer __construct_backward_and_swap_(__split_buffer &__v, pointer __p);
		void __construct_backward_and_swap_(__split_buffer &__v);
		void __append(size_type __n, const_reference __val);
		size_type __recommend(size_type __new_size) const;
		void __construct_at_end(size_type _n, const_reference _val);
		inline void __destruct_at_end(pointer __new_last);
		void __shift_right(pointer __pos, pointer __end_holder, pointer __p);
		inline void move_backward(pointer _first, pointer _last, pointer _result);
		inline iterator __make_iter(pointer __p);
		inline const_iterator __make_iter(const_pointer __p) const;


	};	// -------------------------------------------------   [ VECTOR ] ----//


	//+------------------------------------------------------------------------+
	//|                         [ Private Tools ]                              |
	//+------------------------------------------------------------------------+
	template<class _Tp, class _Allocator>
	typename vector<_Tp, _Allocator>::pointer 
	vector<_Tp, _Allocator>::__construct_backward_and_swap_(__split_buffer &__v, pointer __p)
	{
		pointer __r = __v.vec.__begin_;
		/* Construct Forward */
		pointer __ptr = __p;
		while (__ptr != __end_)
			__v.vec.__alloc.construct(__v.vec.__end_++, *__ptr++);

		/* Construct Backward */
		__ptr = __p;
		while (__ptr != __begin_)
			__v.vec.__alloc.construct(--__v.vec.__begin_, *--__ptr);

		/* Swap */
		swap (__v.vec);
		return (__r);
	}
	template<class _Tp, class _Allocator>
	void vector<_Tp, _Allocator>::__construct_backward_and_swap_(__split_buffer &__v)
	{
		/* Construct Backward */
		pointer __e = __end_;
		while (__e != __begin_)
			__v.vec.__alloc.construct(--__v.vec.__begin_, *--__e);

		/* Swap */
		swap (__v.vec);
	}

	template<class _Tp, class _Allocator>
	void 
	vector<_Tp, _Allocator>::__append(size_type __n, const_reference __val)
	{
		if (static_cast<size_type>(__end_cap_ - __end_) >= __n)
		{
			/* Constraction at end */
			__construct_at_end(__n, __val);				// add __val until reach to the "new size"
		}
		else
		{
			__split_buffer __v(__recommend(size() + __n), size(), __alloc);
			__construct_backward_and_swap_(__v);		//__begin_, __end_, __end_cap_ now point on the new vector
			__construct_at_end(__n, __val);				// add ( __val ) until reach to the "new size"
		}
	}

 	template<class _Tp, class _Allocator>
	typename vector<_Tp, _Allocator>::size_type 
	vector<_Tp, _Allocator>::__recommend(size_type __new_size) const
	{
		const size_type __ms = max_size();
		if (__new_size > __ms)
			__throw_length_error();
		const size_type __cap = capacity();
		if (__cap >= __ms / 2)
			return __ms;
		return std::max<size_type>(2*__cap, __new_size);
	}

	template<class _Tp, class _Allocator>
	void vector<_Tp, _Allocator>::__construct_at_end(size_type __n, const_reference __val)
	{
		for (; __n; --__n, ++__end_)
			__alloc.construct(__end_, __val);
	}

	template <class _Tp, class _Allocator>
	inline void vector<_Tp, _Allocator>::__destruct_at_end(pointer __new_last)
	{
		while (__new_last != __end_)
			__alloc.destroy(--__end_);
	}

	template<class _Tp, class _Allocator>
	inline void vector<_Tp, _Allocator>::move_backward(pointer _first, pointer _last, pointer _result)
    {
        while (_first != _last)
            *--_result = *--_last;
    }
	
	template <class _Tp, class _Allocator>
	void vector<_Tp, _Allocator>::__shift_right(pointer __pos, pointer __end_holder, pointer __to)
    {
        pointer __old_end_ = __end_;
        difference_type __n = __end_ - __to;

        for (pointer __i = __pos + __n; __i < __end_holder; ++__i, ++__end_)
            __alloc.construct( __end_, *__i);
        move_backward(__pos, __pos + __n, __old_end_);
    }
	
	template <class _Tp, class _Allocator>
	inline typename vector<_Tp, _Allocator>::iterator
	vector<_Tp, _Allocator>::__make_iter(pointer __p)
	{
		return iterator(__p);
	}
	template <class _Tp, class _Allocator>
	inline typename vector<_Tp, _Allocator>::const_iterator
	vector<_Tp, _Allocator>::__make_iter(const_pointer __p) const
	{
		return const_iterator(__p);
	}


	//+------------------------------------------------------------------------+
	//|                     [  non-member overloads  ]                         |
	//+------------------------------------------------------------------------+

	//     +-------------------------------------------------------------------+
	// ==> |                  [ ft::relational operators ]                     |
	//     +-------------------------------------------------------------------+


	template <class T, class Alloc>  
	bool operator == (const vector<T, Alloc> &__x, const vector<T, Alloc> &__y)
	{
		return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin());
	}

	template <class T, class Alloc>  
	bool operator != (const vector<T,Alloc> &__x, const vector<T,Alloc> &__y)
	{
		return !(__x ==__y);
	}

	template <class T, class Alloc>  
	bool operator <  (const vector<T,Alloc> &__x, const vector<T,Alloc> &__y)
	{
		return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
	}

	template <class T, class Alloc>  
	bool operator >  (const vector<T,Alloc>& __x, const vector<T,Alloc>& __y)
	{
		return __y < __x;
	}

	template <class T, class Alloc>  
	bool operator <= (const vector<T,Alloc>& __x, const vector<T,Alloc>& __y)
	{
		return  !(__y < __x);	
	}
	template <class T, class Alloc>  
	bool operator >= (const vector<T,Alloc>& __x, const vector<T,Alloc>& __y)
	{
		return  !(__x < __y);		
	}
	
	//     +-------------------------------------------------------------------+
	// ==> |                         [ ft::swap ]                              |
	//     +-------------------------------------------------------------------+

	template <class _Tp, class _Allocator>
	inline void swap(vector<_Tp, _Allocator> &__x, vector<_Tp, _Allocator> &__y)
	{
		__x.swap(__y);
	}

}	//namespace ft
#endif