/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:31 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/24 16:25:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "../Tree/tree.hpp"
#include <memory>
#include <exception>
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
	typedef Key																	key_type;
	typedef T																	mapped_type;
	typedef std::pair<const key_type, mapped_type>								value_type;
	typedef Compare																key_compare;
	typedef Allocator															allocator_type;
	typedef typename allocator_type::reference									reference;
	typedef typename allocator_type::const_reference							const_reference;
	typedef typename allocator_type::pointer									pointer;
	typedef typename allocator_type::const_pointer								const_pointer;
	typedef typename allocator_type::difference_type							difference_type;
	typedef typename allocator_type::size_type									size_type;

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
	typedef __tree<value_type, value_compare, allocator_type>  				 	__tree_base_;
	__tree_base_ __base_;
public:
	typedef typename __tree_base_::node_pointer   								node_pointer;
	typedef typename __tree_base_::iterator										iterator;
	typedef typename __tree_base_::const_iterator								const_iterator;

	//+------------------------------------------------------------------------+
	//|                                                                        |
	//|                          [ Member functions ]                          |
	//|                                                                        |
	//+------------------------------------------------------------------------+
		//+--------------------------------------------------------------------+
		//|                          [ Constractor ]                           |
		//+--------------------------------------------------------------------+

		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: __base_(value_compare(comp), alloc)
		{}

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type &alloc = allocator_type());
    	
		map(const map &__x) : __base_(__x.__base_)
        {
            insert(__x.begin(), __x.end());
        }

 		map &operator = (const map &__x)
        {
            if (this != &__x) {
                __base_.clear();
                __base_.value_comp() = __x.__base_.value_comp();
                insert(__x.begin(), __x.end());
            }
            return *this;
        }

		~map() {};
	

		node_pointer __root() const
        {
			return __base_.__root();
		}

		//+--------------------------------------------------------------------+
		//|                           [ Iterators ]                            |
		//+--------------------------------------------------------------------+
		iterator begin()
		{
			return __base_.begin();
		}
		iterator end()
		{
			return __base_.end();
		}
		const_iterator begin() const 
		{
			return __base_.begin();
		}
		const_iterator end() const 
		{
			return __base_.end();
		}

		//+--------------------------------------------------------------------+
		//|                            [ Capacity ]                            |
		//+--------------------------------------------------------------------+
		bool empty() const
		{
			return __base_.empty();
		}
		size_type size() const
		{
			return __base_.size();
		}
		size_type max_size() const
		{
			return __base_.max_size();
		}

		//+--------------------------------------------------------------------+
		//|                             [ Access ]                             |
		//+--------------------------------------------------------------------+
		mapped_type &operator [] (const key_type &__k)
		{
			return (*((this->insert(std::make_pair(__k,mapped_type()))).first)).second;
		}

		mapped_type &at (const key_type &__k)
		{
			node_pointer __parent = __base_.__root();
			char __x = __base_.__find_where(__parent, std::make_pair(__k,mapped_type()));
			if (__x == '0')
				return __parent->__value_.second;
			else
				std::__throw_out_of_range("map::at:  key not found");
		}
		const mapped_type &at (const key_type &__k) const
		{
			return at(__k);
		}

		//+--------------------------------------------------------------------+
		//|                            [ Modifiers ]                            |
		//+--------------------------------------------------------------------+
		//------------------------------------------------------------< insert >
		std::pair<iterator, bool> insert(const value_type &val)
		{
			return (__base_.__insert_unique(val));
		}
		iterator insert(iterator position, const value_type &val)
		{
			return (__base_.__insert_unique(position.__ptr_, val));
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert(*first);
		}

		//--------------------------------------------------------------< swap >
		void swap (map &__x)
		{
			__base_.swap(__x.__base_);	
		}

		//-------------------------------------------------------------< clear >
		void clear()
		{
			__base_.clear();
		}
		//+--------------------------------------------------------------------+
		//|                            [ Observers ]                           |
		//+--------------------------------------------------------------------+
		key_compare key_comp() const	//used to compare Key : __value_.first
		{
			return  __base_.value_comp().comp;
		}
		value_compare value_comp() const	//used to compare __value_ it self
		{
			return  value_compare(__base_.value_comp().comp);
		}
		//+--------------------------------------------------------------------+
		//|                           [ Operations ]                           |
		//+--------------------------------------------------------------------+
		// iterator find (const key_type &__k)
		// {}
		// const_iterator find (const key_type& k) const
		// {}

};


}

#endif