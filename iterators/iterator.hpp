/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:43:58 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/05 11:27:37 by obelkhad         ###   ########.fr       */
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
		typedef Iter																iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::iterator_category		iterator_category;
		typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference				reference;

	//+------------------------------------------------------------------------+
	//|																		   |
	//|			 		           Move iterator	    					   |
	//|																		   |
	//+------------------------------------------------------------------------+
		//+--------------------------------------------------------------------+
		//|					           base()     							   |
		//+--------------------------------------------------------------------+
		iterator_type base() const { return (this->__i); }

		//+--------------------------------------------------------------------+
		//|					         Constructors                              |
		//+--------------------------------------------------------------------+
		// default-constructible
		base_Iterator()
		{}

		// parameterized-constructible,
		base_Iterator(iterator_type __x): __i(__x) 
		{}
		
		// copy-constructible,
 		template <class U> 
		base_Iterator(const base_Iterator<U> &__u) : __i((iterator_type)__u.base())
		{}

		// copy-assignable 
		base_Iterator &operator = (const base_Iterator &__x)
    	{
        	if (this != &__x)
				__i = __x.__i;
			return *this;
    	}

		// destructible
		~base_Iterator()
		{}

		//+-------------------------------------------------------------------+
		//|					    Input::Dereferenceable	 		  	  	      |
		//+-------------------------------------------------------------------+
		reference operator * () const { return *__i; }

		pointer  operator -> () const { return  std::addressof(operator*()); }

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
		
		base_Iterator operator - (difference_type __n) const
        {
			return this->__i - __n;
		}

		//[inline] keyword simply include the funtion body in where it called, 
		//to avoid multipl jmp form main to this function for exmple.
		//+-------------------------------------------------------------------+
		//|				     Compound Assignment Operators			 		  |
		//+-------------------------------------------------------------------+
		base_Iterator &operator += (difference_type __n)
		{
			__i += __n;
			return *this;
		}

		base_Iterator &operator -= (difference_type __n)
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
	private:
    	iterator_type __i;
	
	};

/*----------------------------------------------------------------------------*/
/*                      Compares the underlying iterators                     */
/*----------------------------------------------------------------------------*/

	template <class Iter1, class Iter2>
	bool operator == (const base_Iterator<Iter1> &__x, const base_Iterator<Iter2> &__y)
	{return __x.base() == __y.base();}
	
	template <class Iter1, class Iter2>
	bool operator != (const base_Iterator<Iter1> &__x, const base_Iterator<Iter2> &__y)
	{return __x.base() != __y.base();}
	template <class Iter1, class Iter2>
	inline bool operator < (const base_Iterator<Iter1> &__x, const base_Iterator<Iter2> &__y)
	{return __x.base() < __y.base();}

	template <class Iter1, class Iter2>
	inline bool operator <= (const base_Iterator<Iter1> &__x, const base_Iterator<Iter2> &__y)
	{return __x.base() <= __y.base();}

	template <class Iter1, class Iter2>
	inline bool operator > (const base_Iterator<Iter1> &__x, const base_Iterator<Iter2> &__y)
	{return __x.base() > __y.base();}

	template <class Iter1, class Iter2>
	inline bool operator >= (const base_Iterator<Iter1> &__x, const base_Iterator<Iter2> &__y)
	{return __x.base() >= __y.base();}

	/*----------------------------------------------------------------------------*/
	/*                      operator+/-(std::reverse_iterator)                    */
	/*----------------------------------------------------------------------------*/
	
	template <class Iterator>  
	base_Iterator<Iterator> operator + (typename base_Iterator<Iterator>::difference_type __n, const base_Iterator<Iterator> &__x)
	{
		return __x.base() + __n; 
	}

	template <class Iterator1, class Iterator2>
	typename base_Iterator<Iterator1>::difference_type 
	operator - (const base_Iterator<Iterator1> &__x,  const base_Iterator<Iterator2> &__y)
	{ return __x.base() - __y.base(); }

}	//namespace ft

#endif