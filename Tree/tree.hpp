/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:28:20 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/16 23:40:49 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP

#include "./tree_iterator.hpp"
#include <iostream>

namespace ft
{
	template <class Tp>
	struct __tree_node 
	{
		typedef __tree_node<Tp>*						pointer;
		typedef Tp 										node_value_type;

		node_value_type 	__value_;
		pointer				__right_;
		pointer 			__left_;
		pointer				__parent_;
		bool 				__is_black_;
	};

	template <class T, class Compare, class Allocator>
	class __tree
	{
	public:
		typedef T																value_type;
		typedef Compare															value_compare;
		typedef Allocator														allocator_type;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename allocator_type::size_type								size_type;
		typedef typename allocator_type::difference_type						difference_type;
	
		typedef typename __tree_node<value_type>::node_value_type				node_value;
		typedef typename __tree_node<value_type>::pointer						node_pointer;

    	typedef __tree_iterator<value_type, node_pointer, difference_type>				iterator;
		typedef __tree_const_iterator<value_type, node_pointer, difference_type>		const_iterator;

		typedef std::allocator<__tree_node<value_type> >						node_allocator;
  

	private:
    	node_pointer 	__begin_node_;
    	node_pointer 	__end_node_;
		size_type		__size;
		value_compare	__comp;
		allocator_type	__alloc;
		node_allocator	__node_alloc;

	public:
		//------------------------------------------------------ [ Costructors ]
		__tree(const value_compare &comp, const allocator_type &alloc, const node_allocator &n_alloc = node_allocator())
		: __size(0), __comp(comp), __alloc(alloc) , __node_alloc(n_alloc)
		{
			__begin_node_ = __end_node_ = __node_alloc.allocate(1);
			__begin_node_->__parent_ = __begin_node_->__right_ = __begin_node_->__left_ = nullptr; 
		}
		~__tree()
		{
			clear();
			__node_alloc.deallocate(__end_node_, 1);
		}


		//------------------------------------------------------------ [ root ]
		node_pointer __root() const
        {
			return __end_node_->__left_;
		}
		value_compare &value_comp()
        {
            return (__comp);
        }
		//--------------------------------------------------------- [ iterator ]
		iterator begin()
		{
			return iterator(__begin_node_);
		}
		const_iterator begin() const
		{
			return const_iterator(__begin_node_);
		}
        iterator end() 
		{
			return iterator(__end_node_);
		}
    	const_iterator end() const
		{
			return const_iterator(__end_node_);
		}

		//------------------------------------------------------------ [ clear ]
		void clear()
		{
			destroy(__root());
			__size = 0;
			__begin_node_ = __end_node_;
    		__end_node_->__left_ = nullptr;
		}

		//------------------------------------------------------------- [ swap ]
		void swap(__tree &__t)
		{
			std::swap(__begin_node_, __t.__begin_node_);
			std::swap(__end_node_, __t.__end_node_);
			std::swap(__size, __t.__size);
			std::swap(__comp, __t.__comp);
			std::swap(__alloc, __t.__alloc);
			std::swap(__node_alloc, __t.__node_alloc);
		}

		//-------------------------------------------------- [ __insert_unique ]
		std::pair<iterator, bool> __insert_unique(const value_type &__v)
		{
			node_pointer __parent = __root();
			char __x = __find_where(__parent, __v);
			node_pointer __child = nullptr;
			bool __inserted = false;
			if (__parent)
			{
				__child = __construct_node(__v);
				__insert_node_at(__parent, __child, __x);
				__inserted = true;
			}
			return std::pair<iterator, bool>(iterator(__child), __inserted);
		}
		

		//---------------------------------------------------------- [ private ]
	private:

		//			=================================================| destroy |
		void destroy(node_pointer __node)
		{
			if (__node)
			{
				destroy(__node->__left_);
				destroy(__node->__right_);
				__alloc.destroy(&__node->__value_);
				__node_alloc.deallocate(__node, 1);
			}
		}

		//======================================================================


		//			========================================| __insert_node_at |

		void __insert_node_at(node_pointer &__parent, node_pointer &__child, char __x)
		{
			if (__x == 'l')
				__parent->__left_ = __child;
			else if (__x == 'r')
				__parent->__right_ = __child;
			__child->__parent_ = __parent;

			if (__begin_node_->__left_)
				__begin_node_ = __begin_node_->__left_;

			// __tree_balance_after_insert(__end_node_->__left_, __child);
			++__size;
		}
		//======================================================================


		//			========================================| __construct_node |

		node_pointer __construct_node(const value_type &__v)
		{
		    node_pointer __n_ptr = __node_alloc.allocate(1);
			__alloc.construct(&__n_ptr->__value_, __v);
			__n_ptr->__right_ = nullptr;
			__n_ptr->__left_ = nullptr;
			__n_ptr->__parent_ = nullptr;
			__n_ptr->__is_black_ = false;
			return __n_ptr;
		}
		//======================================================================


		//			=============================================| __find_where |

		char __find_where(node_pointer &__parent, const value_type &__v)
		{
			if (__parent != nullptr)
			{
				while (true)
				{
					if (value_comp()(__v, __parent->__value_))
					{
						if (__parent->__left_ == nullptr)
							return 'l';
						else
							__parent = __parent->__left_;
					}
					else if (value_comp()(__parent->__value_, __v))
					{
						if (__parent->__right_ == nullptr)
							return 'r';
						else
							__parent = __parent->__right_;
					}
					else
					{
						__parent = nullptr;
						return '0';
					}
				}			
			}
			__parent = __end_node_;
			return 'l';
		}
		//======================================================================	
		
		
		//			=============================| __tree_balance_after_insert |

		// void __tree_balance_after_insert(node_pointer &__root, node_pointer __x)
		// {
		// 	__x->__is_black_ = __x == __root;
		// 	while (__x != __root && !__x->__parent_unsafe()->__is_black_)
		// 	{
		// 		// __x->__parent_ != __root because __x->__parent_->__is_black == false
		// 		if (__tree_is_left_child(__x->__parent_unsafe()))
		// 		{
		// 			_NodePtr __y = __x->__parent_unsafe()->__parent_unsafe()->__right_;
		// 			if (__y != nullptr && !__y->__is_black_)
		// 			{
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = true;
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = __x == __root;
		// 				__y->__is_black_ = true;
		// 			}
		// 			else
		// 			{
		// 				if (!__tree_is_left_child(__x))
		// 				{
		// 					__x = __x->__parent_unsafe();
		// 					__tree_left_rotate(__x);
		// 				}
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = true;
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = false;
		// 				__tree_right_rotate(__x);
		// 				break;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			_NodePtr __y = __x->__parent_unsafe()->__parent_->__left_;
		// 			if (__y != nullptr && !__y->__is_black_)
		// 			{
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = true;
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = __x == __root;
		// 				__y->__is_black_ = true;
		// 			}
		// 			else
		// 			{
		// 				if (__tree_is_left_child(__x))
		// 				{
		// 					__x = __x->__parent_unsafe();
		// 					__tree_right_rotate(__x);
		// 				}
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = true;
		// 				__x = __x->__parent_unsafe();
		// 				__x->__is_black_ = false;
		// 				__tree_left_rotate(__x);
		// 				break;
		// 			}
		// 		}
		// 	}
		// }
		//======================================================================	
	};
}
#endif