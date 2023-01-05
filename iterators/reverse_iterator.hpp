/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:43:24 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/05 11:07:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "../traits/iterator_traits.hpp"

namespace ft
{
	template <class __Iter>
	class reverse_iterator
	{
	public:
		typedef __Iter																iterator_type;
		typedef typename ft::iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename ft::iterator_traits<iterator_type>::value_type				value_type;
		typedef typename ft::iterator_traits<iterator_type>::pointer				pointer;
		typedef typename ft::iterator_traits<iterator_type>::reference				reference;

		//+-------------------------------------------------------------------+
		//|					          Constructors							  |
		//+-------------------------------------------------------------------+
		reverse_iterator() :  current() {}
		explicit reverse_iterator(iterator_type __x) : current(__x) {}
		template <class Tp>
		reverse_iterator (const reverse_iterator<Tp> &__x) : current(__x.base())
		{}

		//+-------------------------------------------------------------------+
		//|					          base()     							  |
		//+-------------------------------------------------------------------+
		iterator_type base() const { return current; }
		
		//+-------------------------------------------------------------------+
		//|					    Input::Dereferenceable	 		  	  	      |
		//+-------------------------------------------------------------------+
		reference operator * () const 
		{
			iterator_type __tmp = current;
			return *--__tmp;
		}
		pointer  operator -> () const 
		{
			return std::addressof(operator*());
		}
		
		//+-------------------------------------------------------------------+
		//|					         Incrementation						  	  |
		//+-------------------------------------------------------------------+
		reverse_iterator &operator ++ ()
		{
			--current;
			return *this;
		}
		reverse_iterator  operator ++ (int) 
		{
			reverse_iterator __tmp(*this);
			--current; 
			return __tmp;
		}

		//+-------------------------------------------------------------------+
		//|					         Decrementation						  	  |
		//+-------------------------------------------------------------------+
		reverse_iterator &operator -- ()
		{
			++current;
			return *this;
		}
		reverse_iterator  operator -- (int)
		{
			reverse_iterator __tmp(*this);
			++current;
			return __tmp;
		}

		//+-------------------------------------------------------------------+
		//|					          Arithmetic						  	  |
		//+-------------------------------------------------------------------+
		reverse_iterator  operator + (difference_type __n) const
		{
			return reverse_iterator(current - __n);
		}
			
		reverse_iterator  operator - (difference_type __n) const
		{
			return reverse_iterator(current + __n);
		}


		//+-------------------------------------------------------------------+
		//|				     Compound Assignment Operators			 		  |
		//+-------------------------------------------------------------------+
		reverse_iterator &operator += (difference_type __n)
		{
			current -= __n;
			return *this;
		}
		
		reverse_iterator &operator -= (difference_type __n)
		{
			current += __n;
			return *this;
		}

		//+-------------------------------------------------------------------+
		//|					          Operator []							  |
		//+-------------------------------------------------------------------+
		reference operator [] (difference_type __n) const
		{
			return *(*this + __n);
		}
	private:
    	iterator_type current;
	};

//-------------------------------------------------------[Non-member functions ]

/*----------------------------------------------------------------------------*/
/*                      Compares the underlying iterators                     */
/*----------------------------------------------------------------------------*/
	template <class __Iter1, class __Iter2>
	inline bool operator == (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{return __x.base() == __y.base();}


	template <class __Iter1, class __Iter2>
	inline bool operator != (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{return __x.base() != __y.base();}


	template <class __Iter1, class __Iter2>
	inline bool operator < (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{return __x.base() > __y.base();}


	template <class __Iter1, class __Iter2>
	inline bool operator <= (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{return __x.base() >= __y.base();}


	template <class __Iter1, class __Iter2>
	inline bool operator > (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{return __x.base() < __y.base();}


	template <class __Iter1, class __Iter2>
	inline bool operator >= (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{return __x.base() <= __y.base();}

	/*----------------------------------------------------------------------------*/
	/*                      operator-(std::reverse_iterator)                      */
	/*----------------------------------------------------------------------------*/
	
	template <class __Iter1, class __Iter2>
	typename reverse_iterator<__Iter1>::difference_type 
	operator - (const reverse_iterator<__Iter1> &__x, const reverse_iterator<__Iter2> &__y)
	{ return __y.base() - __x.base(); }

	/*----------------------------------------------------------------------------*/
	/*                      operator+(std::reverse_iterator)                      */
	/*----------------------------------------------------------------------------*/

	template <class __Iter>
	inline reverse_iterator<__Iter>
	operator + (typename reverse_iterator<__Iter>::difference_type __n, const reverse_iterator<__Iter> &__x)
	{ return reverse_iterator<__Iter>(__x.base() - __n); }
	
}


#endif