/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:43:58 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/22 20:43:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "../traits/iterator_traits.hpp"

namespace ft
{
	template <class Iter>
	class base_Iterator
	{
	public:
		typedef Iter                                              				iterator_type;
		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename iterator_traits<iterator_type>::value_type				value_type;
		typedef typename iterator_traits<iterator_type>::pointer				pointer;
		typedef value_type														reference;
		typedef value_type&														const_reference;
		typedef std::random_access_iterator_tag									iterator_category;


		//+-------------------------------------------------------------------+
		//|					          base()     							  |
		//+-------------------------------------------------------------------+
		iterator_type base() const	{ return (this->__i); }

		//+-------------------------------------------------------------------+
		//|					          Constructors							  |
		//+-------------------------------------------------------------------+
		// default-constructible
		base_Iterator() : __i() { }

		// copy-constructible,
 		template <class _Up> base_Iterator(const base_Iterator<_Up> &__u) : __i(__u.base()) { }
		base_Iterator(const base_Iterator &__x): __i(__x.base())
		{}

		// parameterized-constructible,
		base_Iterator(const iterator_type &__x): __i(__x) 
		{}

		// copy-assignable 
		base_Iterator &operator = (const base_Iterator &__x)
    	{
        	if (this != &__x)
				__i = __x.__i;
			return *this;
    	}

		// destructible
		~base_Iterator() { }

		//+-------------------------------------------------------------------+
		//|					    Input::Dereferenceable	 		  	  	      |
		//+-------------------------------------------------------------------+
		// reference operator * () const { return *__i; }

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
		
		difference_type operator + (const base_Iterator &iter)
		{
			return (base() + iter.base());
		}
		
		base_Iterator  operator - (difference_type __n) const
        {
			return this->__i - __n;
		}
		
		difference_type operator - (const base_Iterator &iter)
		{
			return (base() - iter.base());
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
		// reference operator [] (difference_type __n) const
		// {
		// 	return __i[__n];
		// }
	private:
    	iterator_type __i;
	};
}	//namespace ft

#endif