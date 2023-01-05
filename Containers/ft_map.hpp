/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:34:31 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/04 21:35:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP

#include "../Tree/tree.hpp"
namespace ft
{
	//+------------------------------------------------------------------------+
	//|                                  Map                                   |
	//+------------------------------------------------------------------------+
	
template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<ft::pair<const Key, T> > > class map
{
	//+------------------------------------------------------------------------+
	//|                                                                        |
	//|                           [ Member types ]                             |
	//|                                                                        |
	//+------------------------------------------------------------------------+
public:
	typedef Key																	key_type;
	typedef T																	mapped_type;
	typedef ft::pair<const key_type, mapped_type>								value_type;
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
	typedef ft::__tree<value_type, value_compare, allocator_type>  				__tree_base_;
	__tree_base_ __base_;
public:
	typedef typename __tree_base_::node_pointer   								node_pointer;
	typedef typename __tree_base_::iterator										iterator;
	typedef typename __tree_base_::const_iterator								const_iterator;
	
	typedef ft::reverse_iterator<iterator>										reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

	node_pointer __root() const
	{ return __base_.__root(); }
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

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: __base_(value_compare(comp), alloc)
		{
			insert(first, last);
		}
    	
		map(const map &__x) : __base_(__x.__base_)
        {
            insert(__x.begin(), __x.end());
        }

 		map &operator = (const map &__x)
        {
            if (this != &__x) {
                __base_.clear();
				__base_.set_value_comp(__x.__base_.value_comp());
                insert(__x.begin(), __x.end());
            }
            return *this;
        }

		~map() {};

		//+--------------------------------------------------------------------+
		//|                           [ Iterators ]                            |
		//+--------------------------------------------------------------------+
		// ITERATOR

		iterator begin() 
		{return iterator(__base_.begin());}

		iterator end()
		{return iterator(__base_.end());}

		const_iterator begin() const
		{return const_iterator(__base_.begin());}

		const_iterator end() const
		{return const_iterator(__base_.end());}

		// REVERCE_ITERATOR
		reverse_iterator rbegin() 
		{return reverse_iterator(__base_.end());}

		reverse_iterator rend() 
		{return reverse_iterator(__base_.begin());}

		const_reverse_iterator rbegin() const
		{return const_reverse_iterator(__base_.end());}

		const_reverse_iterator rend() const
		{return const_reverse_iterator(__base_.begin());}
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
			return (*((this->insert(ft::make_pair(__k, mapped_type()))).first)).second;
		}

		mapped_type &at (const key_type &__k)
		{
			node_pointer __parent = __base_.__root();
			char __x = __base_.__find_where(__parent, ft::make_pair(__k, mapped_type()));
			if (__x == '0')
				return __parent->__value_.second;
			else
				std::__throw_out_of_range("map::at: key not found");
		}
		const mapped_type &at (const key_type &__k) const
		{
			return at(__k);
		}

		//+--------------------------------------------------------------------+
		//|                            [ Modifiers ]                            |
		//+--------------------------------------------------------------------+
		ft::pair<iterator, bool> insert(const value_type &__val)
		{
			return (__base_.__insert_unique(__val));
		}
		iterator insert(iterator position, const value_type &__val)
		{
			return (__base_.__insert_unique(position.__ptr_, __val));
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			for (; first != last; ++first)
				insert(*first);
		}
		
    	void erase (iterator position)
		{
			__base_.__erase(position);
		}
		size_type erase (const key_type &__k)
		{
			iterator __it = find(__k);
			return (__it == end()) ? 0 : (__base_.__erase(__it), 1);
		}
		void erase (iterator first, iterator last)
		{
			iterator it = first;
			while (it != last)
			{
				++it;
				__base_.__erase(first++);
				first = it;
			}
		}
		
		
		void swap (map &__x)
		{
			__base_.swap(__x.__base_);	
		}

		void clear()
		{
			__base_.clear();
		}

		//+--------------------------------------------------------------------+
		//|                            [ Observers ]                           |
		//+--------------------------------------------------------------------+
		key_compare key_comp() const		//used to compare Key : __value_.first
		{
			return  __base_.value_comp().comp;
		}
		value_compare value_comp() const	//used to compare __value_ it self
		{
			key_compare __c = __base_.value_comp().comp;
			return  value_compare(__c);
		}

		//+--------------------------------------------------------------------+
		//|                           [ Operations ]                           |
		//+--------------------------------------------------------------------+
		iterator find (const key_type &__k)
		{
			return __base_.__find(value_type(__k, mapped_type()));
		}
		const_iterator find (const key_type &__k) const
		{
			return __base_.__find(value_type(__k, mapped_type()));
		}
		size_type count (const key_type &__k) const
		{
			return __base_.__count(value_type(__k, mapped_type()));
		}
      	iterator lower_bound (const key_type &__k)
		{
			return __base_.__lower_bound(value_type(__k, mapped_type()), __root());
		}
		const_iterator lower_bound (const key_type &__k) const
		{
			return __base_.__lower_bound(value_type(__k, mapped_type()) , __root());
		}
      	iterator upper_bound (const key_type &__k)
		{
			return __base_.__upper_bound(value_type(__k, mapped_type()), __root());
		}
		const_iterator upper_bound (const key_type &__k) const
		{
			return __base_.__upper_bound(value_type(__k, mapped_type()), __root());
		}
		ft::pair<iterator,iterator> equal_range (const key_type &__k)
		{
			typedef ft::pair<iterator,iterator> __x;
			if (__root() == nullptr)
				return __x(end(), end());
			return __x(lower_bound(__k), upper_bound(__k));
		}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type &__k) const
		{
			typedef ft::pair<const_iterator,const_iterator> __x;
			if (__root() == nullptr)
				return __x(end(), end());
			return __x(lower_bound(__k), upper_bound(__k));
		}

		//+--------------------------------------------------------------------+
		//|                            [ Allocator ]                           |
		//+--------------------------------------------------------------------+
		allocator_type get_allocator() const
		{
			return __base_.alloc();
		}
};
	//+------------------------------------------------------------------------+
	//|                     [  non-member overloads  ]                         |
	//+------------------------------------------------------------------------+

	//     +-------------------------------------------------------------------+
	// ==> |                  [ ft::relational operators ]                     |
	//     +-------------------------------------------------------------------+
	template <class Key, class T, class Compare, class Alloc>
	bool operator == (const map<Key, T, Compare, Alloc> &__x, const map<Key, T, Compare, Alloc> &__y)
	{
		return	__x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator != (const map<Key, T, Compare, Alloc> &__x, const map<Key, T, Compare, Alloc> &__y)
	{
		return !(__x == __y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator < (const map<Key, T, Compare, Alloc> &__x, const map<Key, T, Compare, Alloc> &__y)
	{
		return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator > (const map<Key, T, Compare, Alloc> &__x, const map<Key, T, Compare, Alloc> &__y)
	{
		return (__y < __x);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator >= (const map<Key, T, Compare, Alloc> &__x, const map<Key, T, Compare, Alloc> &__y)
	{
		return !(__x < __y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator <= (const map<Key, T, Compare, Alloc> &__x, const map<Key, T, Compare, Alloc> &__y)
	{
		return !(__y < __x);
	}
	//     +-------------------------------------------------------------------+
	// ==> |                         [ ft::swap ]                              |
	//     +-------------------------------------------------------------------+

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key, T, Compare, Alloc> &__x, map<Key, T, Compare, Alloc> &__y)
	{
		__x.swap(__y);
	}


}

#endif