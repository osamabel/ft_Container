/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:43:58 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/23 10:18:45 by obelkhad         ###   ########.fr       */
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
		typedef typename iterator_traits<iterator_type>::iterator_category		iterator_category;
		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename iterator_traits<iterator_type>::value_type				value_type;
		typedef typename iterator_traits<iterator_type>::pointer				pointer;
		typedef typename iterator_traits<iterator_type>::reference				reference;

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
		reference operator * () const { return *__i; }

		// pointer  operator -> () const { return __i; }
		pointer  operator -> () const { return std::addressof(operator*()); }   //return (pointer)_VSTD::addressof(*__i);

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

		inline bool operator == (const base_Iterator &__x)
		{
			return this->base() == __x.base();
		}

		inline bool operator != (const base_Iterator &__x)
		{
			return this->base() != __x.base();
		}

		inline bool operator < (const base_Iterator &__x)
		{
			return this->base() < __x.base();
		}
	
		inline bool operator <= (const base_Iterator &__x)
		{
			return this->base() <= __x.base();
		}

		inline bool operator > (const base_Iterator &__x)
		{
			return this->base() > __x.base();
		}
		
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
	private:
    	iterator_type __i;
	};


	template <class Iter>
	class reverse_iterator
	{
		typedef Iter                                              				iterator_type;
		typedef typename iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename iterator_traits<iterator_type>::value_type				value_type;
		typedef typename iterator_traits<iterator_type>::pointer				pointer;
		typedef typename iterator_traits<iterator_type>::reference				reference;

	public:
		//+-------------------------------------------------------------------+
		//|					          Constructors							  |
		//+-------------------------------------------------------------------+
		reverse_iterator() :  current() {}
		explicit reverse_iterator(iterator_type __x) : current(__x) {}
		// template <class _Up> reverse_iterator(const reverse_iterator<_Up>& __u) : __t(__u.base()), current(__u.base()) {}
		// template <class _Up> reverse_iterator& operator=(const reverse_iterator<_Up>& __u)
		// {
		// 	__t = current = __u.base();
		// 	return *this;
		// }
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
			return _VSTD::addressof(operator*());
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
			--current; return __tmp;
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
    	Iter current;
	};


//-------------------------------------------------------[Non-member functions ]

/*----------------------------------------------------------------------------*/
/*                      Compares the underlying iterators                     */
/*----------------------------------------------------------------------------*/
template <class Iter1, class Iter2>
inline bool operator == (const reverse_iterator<Iter1> &__x, const reverse_iterator<Iter2> &__y)
{return __x.base() == __y.base();}


template <class Iter1, class Iter2>
inline bool operator != (const reverse_iterator<Iter1> &__x, const reverse_iterator<Iter2> &__y)
{return __x.base() != __y.base();}


template <class Iter1, class Iter2>
inline bool operator < (const reverse_iterator<Iter1> &__x, const reverse_iterator<Iter2> &__y)
{return __x.base() > __y.base();}


template <class Iter1, class Iter2>
inline bool operator <= (const reverse_iterator<Iter1> &__x, const reverse_iterator<Iter2> &__y)
{return __x.base() >= __y.base();}


template <class Iter1, class Iter2>
inline bool operator > (const reverse_iterator<Iter1> &__x, const reverse_iterator<Iter2> &__y)
{return __x.base() < __y.base();}


template <class Iter1, class Iter2>
inline bool operator >= (const reverse_iterator<Iter1> &__x, const reverse_iterator<Iter2> &__y)
{return __x.base() <= __y.base();}

/*----------------------------------------------------------------------------*/
/*                      operator-(std::reverse_iterator)                      */
/*----------------------------------------------------------------------------*/
template <class _Iter1, class _Iter2>
inline typename reverse_iterator<_Iter1>::difference_type
operator - (const reverse_iterator<_Iter1>& __x, const reverse_iterator<_Iter2>& __y)
{
    return __y.base() - __x.base();
}

/*----------------------------------------------------------------------------*/
/*                      operator+(std::reverse_iterator)                      */
/*----------------------------------------------------------------------------*/
template <class Iter>
inline reverse_iterator<Iter>
operator + (typename reverse_iterator<Iter>::difference_type __n, const reverse_iterator<Iter> &__x)
{return reverse_iterator<Iter>(__x.base() - __n);}
}	//namespace ft

#endif