/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 09:55:25 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/04 21:35:40 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET
#define FT_SET

#include "../Tree/tree.hpp"

namespace ft
{
	template < 
			class Key, 									// set::key_type/value_type
	        class Compare = std::less<Key>,				// set::key_compare/value_compare
			class Allocator = std::allocator<Key>     	// set::allocator_type           
			> class set
	{
	public:
		typedef Key																key_type;
		typedef key_type														value_type;
		typedef Compare															key_compare;
		typedef key_compare														value_compare;
		typedef Allocator														allocator_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename allocator_type::difference_type						difference_type;
		typedef typename allocator_type::size_type								size_type;

	private:
		typedef ft::__tree<value_type, value_compare, allocator_type>			__tree_base_;
		__tree_base_ 	__base_;
	
	public:
		typedef typename __tree_base_::node_pointer   							node_pointer;
		typedef typename __tree_base_::const_iterator							iterator;
		typedef typename __tree_base_::const_iterator							const_iterator;
		typedef typename __tree_base_::iterator									cast_iterator;
		typedef ft::reverse_iterator<iterator>									reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
	
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
		explicit set (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: __base_(comp, alloc)
		{
		}

		template <class InputIterator>
		set (InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
		: __base_(comp, alloc)
		{
			insert(first, last);
		}

		set (const set &__x) : __base_(__x.__base_)
		{
			insert(__x.begin(), __x.end());
		}
		
		set &operator = (const set &__x)
		{
			if (this != &__x)
			{
				__base_.clear();
				__base_.set_value_comp(__x.__base_.value_comp());
				insert(__x.begin(), __x.end());
			}
			return *this;
		}

		~set()
		{}

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
		//|                            [ Modifiers ]                            |
		//+--------------------------------------------------------------------+
		ft::pair<iterator,bool> insert (const value_type &__val)
		{
			return __base_.__insert_unique(__val);
		}
		iterator insert (iterator position, const value_type &__val)
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
			__base_.erase(position.__ptr_);
		}
		size_type erase (const value_type &__val)
		{
			iterator __it = find(__val);
			return (__it == end()) ? 0 : (__base_.erase(__it.__ptr_), 1);
		}
		void erase (iterator first, iterator last)
		{
			iterator it = first;
			while (it != last)
			{
				++it;
				__base_.erase(first.__ptr_);
				first = it;
			}
		}

		void swap (set &__x)
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
		key_compare key_comp() const
		{
			return  __base_.value_comp();
		}
		value_compare value_comp() const
		{
			return  __base_.value_comp();
		}
		//+--------------------------------------------------------------------+
		//|                           [ Operations ]                           |
		//+--------------------------------------------------------------------+
		iterator find (const value_type &__val) const
		{
			return __base_.__find(__val);
		}

		size_type count (const value_type &__val) const
		{
			return __base_.__count(__val);
		}

		iterator lower_bound (const value_type &__val) const
		{
			return __base_.__lower_bound(__val , __root());
		}

		const_iterator upper_bound (const value_type &__val) const
		{
			return __base_.__upper_bound(__val, __root());
		}

		ft::pair<iterator, iterator> equal_range (const value_type &__val) const
		{
			typedef ft::pair<iterator,iterator> __x;
			if (__root() == nullptr)
				return __x(end(), end());
			return __x(lower_bound(__val), upper_bound(__val));
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
	template <class T, class Compare, class Alloc>
	bool operator == (const set<T, Compare, Alloc> &__x, const set<T, Compare, Alloc> &__y)
	{
		return	__x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin());
	}

	template <class T, class Compare, class Alloc>
	bool operator != (const set<T, Compare, Alloc> &__x, const set<T, Compare, Alloc> &__y)
	{
		return !(__x == __y);
	}

	template <class T, class Compare, class Alloc>
	bool operator < (const set<T, Compare, Alloc> &__x, const set<T, Compare, Alloc> &__y)
	{
		return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
	}

	template <class T, class Compare, class Alloc>
	bool operator > (const set<T, Compare, Alloc> &__x, const set<T, Compare, Alloc> &__y)
	{
		return (__y < __x);
	}

	template <class T, class Compare, class Alloc>
	bool operator >= (const set<T, Compare, Alloc> &__x, const set<T, Compare, Alloc> &__y)
	{
		return !(__x < __y);
	}
	
	template <class T, class Compare, class Alloc>
	bool operator <= (const set<T, Compare, Alloc> &__x, const set<T, Compare, Alloc> &__y)
	{
		return !(__y < __x);
	}
	//     +-------------------------------------------------------------------+
	// ==> |                         [ ft::swap ]                              |
	//     +-------------------------------------------------------------------+

	template <class T, class Compare, class Alloc>
	void swap (set<T, Compare, Alloc> &__x, set<T, Compare, Alloc> &__y)
	{
		__x.swap(__y);
	}

}

#endif