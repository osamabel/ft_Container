/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:31 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/16 19:16:55 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "../Tree/tree.hpp"
#include <memory>
namespace ft
{
	//+------------------------------------------------------------------------+
	//|                                  Map                                   |
	//+------------------------------------------------------------------------+
	
template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T> > > class map
{
	//+------------------------------------------------------------------------+
	//|                                                                        |
	//|                           [ Member types ]                             |
	//|                                                                        |
	//+------------------------------------------------------------------------+
public:
	typedef Key														key_type;
	typedef T														mapped_type;
	typedef std::pair<const key_type, mapped_type>					value_type;
	typedef Compare													key_compare;
	typedef Allocator												allocator_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef typename allocator_type::difference_type				difference_type;
	typedef typename allocator_type::size_type						size_type;

	class value_compare
	{
		friend class map;
	protected:
		key_compare comp;
		value_compare(key_compare c) : comp(c) {}
	public:
		bool operator()(const value_type &__x, const value_type &__y) const
		{
			return comp(__x.first, __y.first);
		}
	};
private:
	typedef __tree<value_type, value_compare, allocator_type>  				 	__base;
	__base _tree_;
public:
	typedef typename __tree<value_type, value_compare, allocator_type>::node_pointer   	node_pointer;
	typedef typename __tree_node<value_type>::node_value_type							node;
	typedef typename __base::iterator								iterator;
	typedef typename __base::const_iterator							const_iterator;

	//+------------------------------------------------------------------------+
	//|                                                                        |
	//|                          [ Member functions ]                          |
	//|                                                                        |
	//+------------------------------------------------------------------------+
		//+--------------------------------------------------------------------+
		//|                          [ Constractor ]                           |
		//+--------------------------------------------------------------------+

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: _tree_(value_compare(comp), alloc)
		{}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type());
    	
		map(const map &__x) : _tree_(__x._tree_)
        {
            insert(__x.begin(), __x.end());
        }

 		map &operator = (const map &__x)
        {
            if (this != &__x) {
                _tree_.clear();
                _tree_.value_comp() = __x._tree_.value_comp();
                insert(__x.begin(), __x.end());
            }
            return *this;
        }

		~map() {};
	

		node_pointer __root() const
        {
			return _tree_.__root();
		}

		//+--------------------------------------------------------------------+
		//|                           [ Iterators ]                            |
		//+--------------------------------------------------------------------+
		iterator begin()
		{
			return _tree_.begin();
		}
		iterator end()
		{
			return _tree_.end();
		}
		const_iterator begin() const 
		{
			return _tree_.begin();
		}
		const_iterator end() const 
		{
			return _tree_.end();
		}

		//+--------------------------------------------------------------------+
		//|                            [ Capacity ]                            |
		//+--------------------------------------------------------------------+
		//+--------------------------------------------------------------------+
		//|                             [ Access ]                             |
		//+--------------------------------------------------------------------+
		//+--------------------------------------------------------------------+
		//|                            [ Modifiers ]                            |
		//+--------------------------------------------------------------------+
		std::pair<iterator, bool> insert(const value_type &val)
		{
			return (_tree_.__insert_unique(val));
		}
		//+--------------------------------------------------------------------+
		//|                            [ Observers ]                           |
		//+--------------------------------------------------------------------+
		//+--------------------------------------------------------------------+
		//|                           [ Operations ]                           |
		//+--------------------------------------------------------------------+
};


}

#endif