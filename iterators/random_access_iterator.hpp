/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:43:58 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/15 13:56:07 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include "../traits/iterator_traits.hpp"

namespace ft
{
	template <class _Iter>
	class base_Iterator
	{
	public:
		typedef _Iter                                               iterator_type;
		typedef typename ft::iterator_traits<T>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T>::value_type			value_type;
		typedef typename ft::iterator_traits<T>::pointer			pointer;
		typedef typename ft::iterator_traits<T>::reference			reference;
		typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;		
	private:
    	iterator_type __i;
	public:
		// geter()
		iterator_type base() const	{ return (this->__i); }

		//+-------------------------------------------------------------------+
		//|					          Constructors							  |
		//+-------------------------------------------------------------------+

		// default-constructible
		base_Iterator() : __i() { }

		// copy-constructible,
 		// template <class _Up> base_Iterator(const base_Iterator<_Up> &__u) : __i(__u.base()) { }
		base_Iterator(const base_Iterator &__x): __i(__x.base()) { }

		// parameterized-constructible,
		base_Iterator(const iterator_type &__x): __i(__x) { }

		// copy-assignable 
		base_Iterator &operator = (const base_Iterator &__x)
    	{
        	if (this != &__x)
				__i = __x.__i;
			return *this;
    	}

		// destructible
		~base_Iterator() { }
	
	private:

		//+-------------------------------------------------------------------+
		//|					    Input::Dereferenceable	 		  	  	      |
		//+-------------------------------------------------------------------+
		reference operator * () const { return *__i; }

		pointer  operator -> () const { return __i; }   //return (pointer)_VSTD::addressof(*__i);

		//+-------------------------------------------------------------------+
		//|					         Incrementation						  	  |
		//+-------------------------------------------------------------------+
		//PRE-Increment ++x
		base_Iterator &operator ++ ()
		{
			++__i;
			return *this;
		}

		//POST-Increment x++
		base_Iterator operator ++ (int)
        {
			base_Iterator __tmp(*this);
			++(*this);
			return __tmp;
		}

		//+-------------------------------------------------------------------+
		//|					         Decrementation						  	  |
		//+-------------------------------------------------------------------+
		//PRE-Decrement --x
		base_Iterator &operator -- ()
		{
			--__i;
			return *this;
		}

		//POST-Decrement x--
		base_Iterator operator -- (int)
        {
			base_Iterator __tmp(*this);
			--(*this);
			return __tmp;
		}

		//+-------------------------------------------------------------------+
		//|					          Arithmetic						  	  |
		//+-------------------------------------------------------------------+
		base_Iterator  operator + (difference_type __n) const
        {
			return this->__i + __n;
		}

		base_Iterator  operator - (difference_type __n) const
        {
			return this->__i - __n;
		}

		//+-------------------------------------------------------------------+
		//|					          Comparisons							  |
		//+-------------------------------------------------------------------+
		//[inline] keyword simply include the funtion body in where it called, 
		//to avoid multipl jmp form main to this function for exmple.

		//==
		inline bool operator == (const base_Iterator &__x)
		{
			return this->base() == __x.base();
		}

		//!=
		inline bool operator != (const base_Iterator &__x)
		{
			return this->base() != __x.base();
		}

		// <
		inline bool operator < (const base_Iterator &__x)
		{
			return this->base() < __x.base();
		}
	
		// <=
		inline bool operator <= (const base_Iterator &__x)
		{
			return this->base() <= __x.base();
		}

		// >
		inline bool operator > (const base_Iterator &__x)
		{
			return this->base() > __x.base();
		}
		
		// >=
		inline bool operator >= (const base_Iterator &__x)
		{
			return this->base() >= __x.base();
		}

		//+-------------------------------------------------------------------+
		//|				     Compound Assignment Operators			 		  |
		//+-------------------------------------------------------------------+
		base_Iterator &operator += (difference_type __n)
		{
			__i += __n;
			return *this;
		}

		base_Iterator& operator -= (difference_type __n)
        {
			__i -= __n;
			return *this;
		}

		//+-------------------------------------------------------------------+
		//|					          Operator []							  |
		//+-------------------------------------------------------------------+
		reference operator [] (difference_type __n) const
		{
			return __i[__n];
		}
	};
}	//namespace ft


#endif