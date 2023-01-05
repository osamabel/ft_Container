/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:40:11 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/04 13:12:38 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{
	template<class T1, class T2> 
	struct pair
	{
		typedef T1 										__first;
        typedef T2 										__second;
        
        T1 first;
        T2 second;

        pair() : first(), second() {}

        template <class U, class V>
        pair(const pair<U, V> &__x) : first(__x.first), second(__x.second) {}
        
		pair(__first const &__x, __second const &__y) : first(__x), second(__y) {}
        
        pair &operator = (const pair &__x)
        {
            first = __x.first;
            second = __x.second;
            return (*this);
        }
		
        void swap(pair &__x)
        {
            std::swap(first,  __x.first);
            std::swap(second, __x.second);
        }
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	};
	
	template <class T1, class T2>
	bool operator == (const pair<T1, T2> &__x, const pair<T1, T2> &__y)
	{
		return (__x.first == __y.first) && (__x.second == __y.second);
	}
	
	template <class T1, class T2>
	bool operator != (const pair<T1, T2> &__x, const pair<T1, T2> &__y)
	{
		return !(__x == __y);
	}
	
	template <class T1, class T2>
	bool operator < (const pair<T1, T2> &__x, const pair<T1, T2> &__y)
	{
		return __x.first < __y.first || ( __x.first == __y.first && __x.second < __y.second);
	}

	template <class T1, class T2>
	bool operator > (const pair<T1, T2> &__x, const pair<T1, T2> &__y)
	{
		return __y < __x;
	}

	template <class T1, class T2>
	bool operator <= (const pair<T1, T2> &__x, const pair<T1, T2> &__y)
	{
		return !(__y < __x);
	}

	template <class T1, class T2>
	bool operator >= (const pair<T1, T2> &__x, const pair<T1, T2> &__y)
	{
		return !(__x < __y);
	}
}

#endif