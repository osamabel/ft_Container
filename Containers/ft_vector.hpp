/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:52:01 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/19 12:20:52 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H
#include <memory>
#include <iostream>

namespace ft
{

	//+----------------------------------------------------------------------+//
	//|                               Vector                                 |//
	//+----------------------------------------------------------------------+//
	template<class _Tp, class _Allocator = std::allocator<_Tp> > 

	class vector
	{
		//+------------------------------------------------------------------+//
		//|                         [ Member types ]                         |//
		//+------------------------------------------------------------------+//

	public:

		typedef _Tp     	                                value_type;
		typedef	_Allocator									allocator_type;
		typedef typename allocator_type::pointer            pointer;            //typdef *_Tp pointer   
		typedef typename allocator_type::reference		    reference;          //typdef &_Tp reference 
		typedef typename allocator_type::const_pointer      const_pointer;      //typdef const *_Tp const_pointer    
		typedef typename allocator_type::const_reference	const_reference;    //typdef const &_Tp const_reference   
		typedef typename allocator_type::size_type          size_type;
		typedef typename allocator_type::difference_type    difference_type;

		pointer                                         __begin_;
		pointer                                         __end_;
		pointer                                         __end_cap_; //end of the allocated memory
		allocator_type									__alloc;

		//+------------------------------------------------------------------+//
		//|                           [ Exceptions ]                         |//
		//+------------------------------------------------------------------+//
		void __throw_length_error() const
		{
			throw std::length_error("vector");
		}
		void __throw_out_of_range() const
		{
			throw std::out_of_range("vector");
		}

		//+------------------------------------------------------------------+//
		//|                          [ Constracors ]                         |//
		//+------------------------------------------------------------------+//
		/* Empty container constructor (default constructor) */
		explicit vector (const allocator_type& alloc = allocator_type())
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(alloc)
		{
			std::cout << "Empty container\n";
		}
		
		/* Fill constructor */
		explicit vector (size_type __n, const value_type& __val = value_type(), const allocator_type& alloc = allocator_type())
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(alloc)
		{
			std::cout << "Fill container\n";
			if (__n > 0)
			{
				/* Vector Allocation with size of (__n), and assign it to __begin_ */
				if (__n > __alloc.max_size())
					__throw_length_error();
				__begin_ = __alloc.allocate(__n);
				__end_ = __begin_;
				__end_cap_ = __begin_ + __n;

				/* Constraction at end */
				while (--__n >= 0)
				{
					__alloc.construct(__end_, __val);
					++__end_;	
				}
			}	
		}

		/* Range constructor */
		// template <class InputIterator>
		// vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
		// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
		// :	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(alloc)
		// {
		// 	std::cout << "range container\n";
		// 	/* Vector Allocation with size of (__n), and assign it to __begin_ */
		// 	size_type __n = static_cast<size_type>(std::distance(first, last));
		// 	if (__n > 0)
		// 	{
		// 		__begin_ 			= __alloc.allocate(__n);
		// 		__end_ 				= __begin_;
		// 		__end_cap_			= __begin_ + __n;
		// 	}

		// 	/* Constraction at end */
		// 	for (size_type i = 0; i < __n ; i++)
		// 		__alloc.construct(__end_++, *first++);
		// }

		/* Copy constructor */
		vector(const vector &__x)
		:	__begin_(nullptr), __end_(nullptr), __end_cap_(nullptr), __alloc(__x.__alloc)
		{
			std::cout << "copy container\n";
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

		~vector ()
		{
			std::cout << "destrctor container\n";
			/* destruct */
			while (__end_ != __begin_)
				__alloc.destroy(--__end_);

			/* deallocate */
			__alloc.deallocate(__begin_, capacity());
		}
		//+------------------------------------------------------------------+//
		//|    	                       [ Capacity ]                     	 |//
		//+------------------------------------------------------------------+//
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
			}	//~__split_buffer() = old vector destroy
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
				while (__end_ != __begin_ + __n)
					__alloc.destroy(--__end_);
			}
		}


	private:
		//+------------------------------------------------------------------+//
		//|                             [ Tools ]                            |//
		//+------------------------------------------------------------------+//
		class __split_buffer
		{
		public:
			ft::vector<value_type, allocator_type> vec;
			__split_buffer(size_type __cap, size_type __size, allocator_type &alloc) : vec(alloc)
			{
				pointer __new;
				__new = __cap != 0 ? alloc.allocate(__cap) : nullptr;
				vec.__begin_ = vec.__end_ = __new + __size;
				vec.__end_cap_ = __new + __cap;
			}
			~__split_buffer()
			{
				std::cout << "old vector destrected \n";
			}
		};

		void __construct_backward_and_swap_(__split_buffer &__v);
		void __append(size_type __n, const_reference __val);
		size_type __recommend(size_type __new_size) const;
		void __construct_at_end(size_type _n, const_reference _val);
	};

	template<class _Tp, class _Allocator>
	void vector<_Tp, _Allocator>::__construct_backward_and_swap_(__split_buffer &__v)
	{
		/* Construct Backward */
		pointer __e = __end_;
		while (__e-- != __begin_)
			__v.vec.__alloc.construct(--__v.vec.__begin_, *__e);

		/* Swap */
		std::swap(__begin_, __v.vec.__begin_);
		std::swap(__end_, __v.vec.__end_);
		std::swap(__end_cap_, __v.vec.__end_cap_);
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
}	//namespace ft
#endif