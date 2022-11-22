/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:49 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/22 20:43:09 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <iterator>
namespace ft
{
	template <class Iterator>
	struct iterator_traits
	{
		typedef ptrdiff_t								difference_type;
		typedef Iterator								value_type;
		typedef Iterator*								pointer;
	};

	template <class T> 
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
	};

	template <class T> 
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								const_pointer;
		typedef const T&								const_refernece;
	};
}	//namespace ft
#endif