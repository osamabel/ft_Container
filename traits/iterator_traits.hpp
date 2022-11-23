/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:49 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/23 12:02:44 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{
	template<class _Category, 
			class _Tp, class _Distance = ptrdiff_t, class _Pointer = _Tp*, class _Reference = _Tp&>
	struct __iterator
	{
		typedef _Tp        value_type;
		typedef _Distance  difference_type;
		typedef _Pointer   pointer;
		typedef _Reference reference;
		typedef _Category  iterator_category;
	};

	template <class __iterator>
	struct iterator_traits
	{
		typedef typename __iterator::difference_type 			difference_type;
		typedef typename __iterator::value_type 				value_type;
		typedef typename __iterator::pointer 		    		pointer;
		typedef typename __iterator::reference 					reference;
		typedef std::random_access_iterator_tag					iterator_category;
	};

	template <class T> 
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;

	};

	template <class T> 
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								const_pointer;
		typedef const T&								const_refernece;
		typedef std::random_access_iterator_tag			iterator_category;
	};
}	//namespace ft
#endif