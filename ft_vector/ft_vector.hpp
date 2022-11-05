/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:52:01 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/05 12:02:44 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <memory>
#include <iostream>

/******************************************************************************/
/************************        __vector_base       **************************/
/******************************************************************************/


template <class _Tp, class _Allocator> class __vector_base
{
protected:
    typedef _Allocator                               allocator_type;
    typedef std::allocator_traits<allocator_type>    __alloc_traits;
    typedef _Tp                                      value_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    // typedef typename __alloc_traits::difference_type difference_type;
    typedef typename __alloc_traits::pointer         pointer;
    // typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef typename __alloc_traits::size_type       size_type;
    // typedef pointer                                  iterator;
    // typedef const_pointer                            const_iterator;

public:
    pointer                                         __begin_;
    pointer                                         __end_;
	allocator_type									__alloc;
    __vector_base() : __begin_(NULL), __end_(NULL)
	{
		std::cout << "Constructor\n";
	};
    ~__vector_base()
	{
		if (__begin_ != NULL)
		{
			clear(); // destroy == destructs
			__alloc_traits::deallocate(__alloc, __begin_, capacity()); //deallocate
		}
	};
	__vector_base(const allocator_type& __a) : __begin_(NULL), __end_(NULL), __alloc(__a){};
	void clear() throw(){__destruct_at_end(__begin_);}
	size_type capacity() const throw() {return static_cast<size_type>(__end_ - __begin_);}
	void __destruct_at_end(pointer __new_last) throw()
	{
		pointer __soon_to_be_end = __end_;
		while (__new_last != __soon_to_be_end)
        	__alloc_traits::destroy(__alloc, --__soon_to_be_end);
    	__end_ = __new_last;
	}

};


/******************************************************************************/
/************************          __vector          **************************/
/******************************************************************************/
template<class _Tp, class Allocator = std::allocator<_Tp> > class vector : public __vector_base<_Tp, Allocator>
{
	
};

#endif