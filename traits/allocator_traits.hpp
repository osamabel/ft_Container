/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:27:52 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/12 15:39:31 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_TRAITS_HPP
#define ALLOCATOR_TRAITS_HPP


template <class Alloc> struct allocator_traits
{
	typedef Alloc										allocator_type;
	typedef typename allocator_type::type_value			type_value;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_pointer		onst_pointer;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::size_type			size_type;    		//size_t:Unsigned integral type
	typedef typename allocator_type::difference_type	difference_type;	//ptrdiff:Result of pointer subtraction


	//----------------------------------------[ ft::allocator_traits::allocate ]
	static pointer allocate (allocator_type& alloc, size_type n)
	{return alloc.allocate(n);}

	//--------------------------------------[ ft::allocator_traits::deallocate ]
	static void deallocate (allocator_type alloc, pointer p, size_type n)
	{alloc.deallocate(p, n);}

	//---------------------------------------[ ft::allocator_traits::construct ]
	// template <class T, class... Args>
	// static void construct (allocator_type alloc, T* p, Args&&... args )
	// {alloc.construct(p, std::forward<Args>(args)...)}

	//-----------------------------------------[ ft::allocator_traits::destroy ]                        
	template <class T>
	static void destroy (allocator_type& alloc, T* p)
	{alloc.destroy(p);}

	//----------------------------------------[ ft::allocator_traits::max_size ]
	static size_type max_size (allocator_type& alloc) // Maximum size possible to allocate
	{return alloc.max_size();}

	//----------------------------------------[ ft::allocator_traits::select_on_container_copy_construction ]
	//In the case of a "custom allocator", copying can be non-trivial
	//https://github.com/dasfex/notes/blob/master/cpp/allocators.md
	// static allocator_type select_on_container_copy_construction (const allocator_type& alloc)
	// {return alloc.select_on_container_copy_construction();}

};


#endif