/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:52:01 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/18 19:46:13 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H
#include <memory>

namespace ft
{

	//+--------------------------------------------------------------------------+//
	//|                                  Vector                                  |//
	//+--------------------------------------------------------------------------+//
	template<class _Tp, class _Allocator = std::allocator<_Tp> > 

	class vector
	{
	//+--------------------------------------------------------------------------+//
	//|                             [ Member types ]                             |//
	//+--------------------------------------------------------------------------+//

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


	//+--------------------------------------------------------------------------+//
	//|                              [ Exceptions ]                              |//
	//+--------------------------------------------------------------------------+//
		void __throw_length_error()
		{
			throw std::length_error("vector");
		}
		void __throw_out_of_range()
		{
			throw std::out_of_range("vector");
		}
	//+--------------------------------------------------------------------------+//
	//|                              [ Constracors ]                             |//
	//+--------------------------------------------------------------------------+//

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
	//+--------------------------------------------------------------------------+//
	//|    	                          [ Capacity ]                             	 |//
	//+--------------------------------------------------------------------------+//
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

	private:
	//+----------------------------------------------------------------------+//
	//|                              Tools                                   |//
	//+----------------------------------------------------------------------+//
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
				std::cout << "old mcha\n";
			}
		};

		void __construct_backward_and_swap_(__split_buffer &__v)
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

	};
}	//namespace ft
#endif