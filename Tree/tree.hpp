/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:28:20 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/25 14:13:53 by obelkhad         ###   ########.fr       */
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
		bool 				__passed_;
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

		typedef ft::__tree_iterator<value_type, node_pointer, difference_type>				iterator;
		typedef ft::__tree_const_iterator<value_type, node_pointer, difference_type>		const_iterator;

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
		// __tree(const value_compare &comp, const allocator_type &alloc, const node_allocator &n_alloc = node_allocator())
		__tree(const value_compare &comp, const allocator_type &alloc)
		: __size(0), __comp(comp), __alloc(alloc) , __node_alloc(alloc)
		{
			__begin_node_ = __end_node_ = __node_alloc.allocate(1);
			__begin_node_->__parent_ = __begin_node_->__right_ = __begin_node_->__left_ = nullptr; 
			__end_node_->__passed_ = false;
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
		const value_compare &value_comp() const
        {
            return (__comp);
        }

		//+--------------------------------------------------------------------+
		//|                           [ Iterators ]                            |
		//+--------------------------------------------------------------------+
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

		//+--------------------------------------------------------------------+
		//|                            [ Capacity ]                            |
		//+--------------------------------------------------------------------+
		bool empty() const
		{
			return (__size == 0);
		}
		size_type size() const
		{
			return __size;
		}
		size_type max_size() const
		{
			return std::min<size_type>(
				__node_alloc.max_size(), std::numeric_limits<difference_type >::max()
			);
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
			node_pointer __child = __parent;
			bool __inserted = false;
			if (__x != '0')
			{
				__child = __construct_node(__v);
				__insert_node_at(__parent, __child, __x);
				__inserted = true;
			}
			return std::pair<iterator, bool>(iterator(__child), __inserted);
		}

		iterator __insert_unique(node_pointer position, const value_type &__v)
		{
			node_pointer __parent = __root();
			char __x = __find_where(position, __parent, __v);
			node_pointer __child = __parent;
			bool __inserted = false;
			if (__x != '0')
			{
				__child = __construct_node(__v);
				__insert_node_at(__parent, __child, __x);
				__inserted = true;
			}
			return iterator(__child);
		}
		//---------------------------------------------------- [ __lower_bound ]
		iterator __lower_bound(const value_type &__v, node_pointer __p)
		{
			node_pointer __r = __end_node_;
			while(__p)
			{
				if (!value_comp()(__p->__value_, __v))   //__p.value >= __v
				{
					__r = __p;
					__p = __p->__left_;
				}
				else									//__p.value < __v	
					__p = __p->__right_;
			}
			return iterator(__r);
		}
		const_iterator __lower_bound(const value_type &__v, node_pointer __p) const
		{
			node_pointer __r = __end_node_;
			while(__p)
			{
				if (!value_comp()(__p->__value_, __v))   //__p.value >= __v
				{
					__r = __p;
					__p = __p->__left_;
				}
				else									//__p.value < __v	
					__p = __p->__right_;
			}
			return const_iterator(__r);
		}

		//---------------------------------------------------- [ __lower_bound ]
		iterator __upper_bound(const value_type &__v, node_pointer __p)
		{
			node_pointer __r = __end_node_;
			while(__p)
			{
				if (value_comp()(__v, __p->__value_))
				{
					__r = __p;
					__p = __p->__left_;
				}
				else
					__p = __p->__right_;
			}
			return iterator(__r);
		}
		const_iterator __upper_bound(const value_type &__v, node_pointer __p) const
		{
			node_pointer __r = __end_node_;
			while(__p)
			{
				if (value_comp()(__p->__value_, __v))
					__p = __p->__right_;
				else
				{
					__p = __p->__right_;
					__r = __p;
				}
			}
			return const_iterator(__r);
		}

		//------------------------------------------------------------ [ __find ]
		iterator __find(const value_type &__v)
		{
			iterator __p = __lower_bound(__v, __root());
			if(__p != end() && !value_comp()(__v, *__p))
				return __p;
			return end();
		}
		//---------------------------------------------------------- [ __count ]
		size_type __count(const value_type &__v) const
		{
			node_pointer __p = __root();
			while (__p)
			{
				if (value_comp()(__v, __p->__value_))
					__p = __p->__left_;
				else if (value_comp()(__p->__value_, __v))
					__p = __p->__right_;
				else
					return 1;
			}
			return 0;
		}

		//----------------------------------------------------------- [ public ]
		//			=============================================| __find_where |
	public:
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
						return '0';
				}			
			}
			__parent = __end_node_;
			return 'l';
		}
		
		char __find_where(node_pointer __hint, node_pointer &__parent, const value_type &__v)
		{
			if (__parent != nullptr)
			{
				node_pointer __ptr = __hint;
				if (__hint == end().__ptr_)
				{
					__ptr = ft::__tree_prev_iter(__hint);
					if (value_comp()(__ptr->__value_, __v))
						return (__parent = __ptr, 'r');
				}
				else if (value_comp()(__v, __hint->__value_))
				{
					if (__hint == begin().__ptr_)
						return (__parent = __hint, 'l');
					else
					{
						__ptr = ft::__tree_prev_iter(__hint);
						if (value_comp()(__ptr->__value_, __v))
						{
							if (__hint->__left_ == nullptr)
								return (__parent = __hint, 'l');
							return (__parent = __ptr, 'r');
						}
					}
				}
				else if (value_comp()(__hint->__value_, __v))
				{
					__ptr = ft::__tree_next_iter(__hint);
					if (__ptr == end().__ptr_)
						return (__parent = __hint, 'r');
					else if (value_comp()(__v, __ptr->__value_))
					{
						if (__hint->__right_ == nullptr)
							return (__parent = __hint, 'r');
						return (__parent = __ptr, 'l');
					}
				}
				return __find_where(__parent, __v);
			}
			__parent = __end_node_;
			return 'l';
		}
		//======================================================================	

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

		void __insert_node_at(node_pointer __parent, node_pointer __child, char __x)
		{

			if (__x == 'l')
				__parent->__left_ = __child;
			else if (__x == 'r')
				__parent->__right_ = __child;
			__child->__parent_ = __parent;
			if (__begin_node_->__left_)
				__begin_node_ = __begin_node_->__left_;

			__tree_balance_after_insert(__end_node_->__left_, __child);
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
			__n_ptr->__passed_ = true;
			return __n_ptr;
		}
		//======================================================================
	
		
		//			=========================================| __left_rotation |
		void	__left_rotation(node_pointer __node)
		{
			node_pointer child = __node->__right_;
			__node->__right_ = child->__left_;
			if (child->__left_)
				child->__left_->__parent_ = __node;
			child->__parent_ = __node->__parent_;
			if(ft::__tree_is_left_child(__node))
				__node->__parent_->__left_ = child;
			else
				__node->__parent_->__right_ = child;
			child->__left_ = __node;
			__node->__parent_ = child;
		}	
		
		//======================================================================


		//			========================================| __right_rotation |
		void	__right_rotation(node_pointer __node)
		{
			node_pointer child = __node->__left_;
			__node->__left_ = child->__right_;
			if (child->__right_)
				child->__right_->__parent_ = __node;
			child->__parent_ = __node->__parent_;
			if (ft::__tree_is_left_child(__node))
				__node->__parent_->__left_ = child;
			else
				__node->__parent_->__right_ = child;
			child->__right_ = __node;
			__node->__parent_ = child;
		}
		//======================================================================	

		//			=============================| __tree_balance_after_insert |

		void __tree_balance_after_insert(node_pointer &__root, node_pointer __x)
		{
			if (__x == __root)
				__x->__is_black_ = true;
			while (__x != __root && __x->__parent_->__is_black_ == false)
			{
				node_pointer __uncle;
				if (ft::__tree_is_left_child(__x->__parent_))
				{
					__uncle = __x->__parent_->__parent_->__right_;
					if (__uncle && __uncle->__is_black_ == false)
					{
						__x = __x->__parent_;
						__x->__is_black_ = true;
						__x = __x->__parent_;
						if (__x == __root)
							__x->__is_black_ = true;
						else
							__x->__is_black_ = false;
						__uncle->__is_black_ = true;
					}
					else
					{
						if (!ft::__tree_is_left_child(__x))
						{
							__x = __x->__parent_;
							__left_rotation(__x);
						}
						__x = __x->__parent_;
						__x->__is_black_ = true;
						__x = __x->__parent_;
						__x->__is_black_ = false;
						__right_rotation(__x);
						break;
					}
				}
				else
				{
					__uncle = __x->__parent_->__parent_->__left_;
					if (__uncle && __uncle->__is_black_ == false)
					{
						__x = __x->__parent_;
						__x->__is_black_ = true;
						__x = __x->__parent_;
						if (__x == __root)
							__x->__is_black_ = true;
						else
							__x->__is_black_ = false;
						__uncle->__is_black_ = true;
					}
					else
					{
						if (ft::__tree_is_left_child(__x))
						{
							__x = __x->__parent_;
							__right_rotation(__x);
						}
						__x = __x->__parent_;
						__x->__is_black_ = true;
						__x = __x->__parent_;
						__x->__is_black_ = false;
						__left_rotation(__x);
						break;
					}
				}				
			}
		}
		//======================================================================	
	};
}
#endif