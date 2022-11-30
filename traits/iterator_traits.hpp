/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:08:49 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 18:14:09 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{
	template<class Category, 
			class Tp, 
			class Distance = ptrdiff_t, 
			class Pointer = Tp*, 
			class Reference = Tp&>
	struct __iterator
	{
		typedef Tp        	value_type;
		typedef Distance  	difference_type;
		typedef Pointer   	pointer;
		typedef Reference 	reference;
		typedef Category  	iterator_category;
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
		typedef ptrdiff_t										difference_type;
		typedef typename remove_cv<T>::type						value_type;
		typedef T*												pointer;
		typedef T&												reference;
		typedef std::random_access_iterator_tag					iterator_category;

	};

}	//namespace ft
#endif