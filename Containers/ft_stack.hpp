/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:17:11 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/01 12:22:12 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//LIFO stack (class template)

#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include "ft_vector.hpp"

namespace ft
{
	//+------------------------------------------------------------------------+
	//|                                                                        |
	//|                               Stack                                    |
	//|                                                                        |
	//+------------------------------------------------------------------------+
	template <class T, class Container = ft::vector<T> > 
	class stack
	{
		//+--------------------------------------------------------------------+
		//|                                                                    |
		//|                         [ Member types ]                           |
		//|                                                                    |
		//+--------------------------------------------------------------------+
	public:
			typedef Container										container_type;
			typedef typename container_type::value_type				value_type;
			typedef typename container_type::size_type				size_type;
			typedef typename container_type::reference				reference;
			typedef typename container_type::const_reference		const_reference;

	public:
		//+--------------------------------------------------------------------+
		//|                                                                    |
		//|                       [ Member functions ]                         |
		//|                                                                    |
		//+--------------------------------------------------------------------+
		//      +--------------------------------------------------------------+
		// ====>|                                            [ Constracors ]   |
		//      +--------------------------------------------------------------+
				/* default constractor*/
				stack() : c()
				{}

				/* copy constractor */
				explicit stack(const container_type &cont = container_type()) : c(cont)
				{}
				stack(const stack &copy) : c(copy.c)
				{}

				/* destractor */
				~stack()()

				/* operator = */
				stack &operator = (const stack& assign)
				{
					c = assign.c;
					return *this;
				}

		//      +--------------------------------------------------------------+
		// ====>|                                         [ Element access ]   |
		//      +--------------------------------------------------------------+
				reference top()
				{ return c.back(); }
				const_reference top() const
				{ return c.back(); }

		//      +--------------------------------------------------------------+
		// ====>|                                               [ Capacity ]   |
		//      +--------------------------------------------------------------+
				bool empty() const
				{ return c.empty(); }

				size_type size() const
				{ return c.size(); }

		//      +--------------------------------------------------------------+
		// ====>|                                               [ Modifiers ]   |
		//      +--------------------------------------------------------------+
				void push( const value_type &value )
				{ c.puch_back(value); }

				void pop()
				{ c.pop_back(); }
		//+--------------------------------------------------------------------+
		//|                                                                    |
		//|                         [ Member object ]                          |
		//|                                                                    |
		//+--------------------------------------------------------------------+
	protected:
		container_type c;


	// template <class T1, class _C1>
    // friend
    // bool
    // operator==(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);

    // template <class T1, class _C1>
    // friend
    // bool
    // operator< (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
	};
		//+--------------------------------------------------------------------+
		//|                                                                    |
		//|                    [NON Member functions ]                         |
		//|                                                                    |
		//+--------------------------------------------------------------------+
	template< class T, class Container >
	bool operator == (const stack<T,Container> &__x, const stack<T,Container> &__y)
	{ return __x.c == __y.c; }

	template< class T, class Container >
	bool operator != ( const stack<T,Container> &__x, const stack<T,Container> &__y)
	{ return !(__x == __y); }

	template< class T, class Container >
	bool operator < (const stack<T,Container> &__x, const stack<T,Container> &__y)
	{return __x.c < __y.c; }
	
	template< class T, class Container >
	bool operator <= (const stack<T,Container> &__x, const stack<T,Container> &__y)
	{return !(__y < __x); }

	template< class T, class Container >
	bool operator > (const stack<T,Container> &__x, const stack<T,Container> &__y)
	{return __y > __x; }

	template< class T, class Container >
	bool operator >= (const stack<T,Container> &__x, const stack<T,Container> &__y)
	{return !(__x < __y); }
}