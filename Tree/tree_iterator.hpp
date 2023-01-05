/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:16:32 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/05 10:26:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
#define TREE_ITERATOR_HPP

namespace ft
{

	template <class Ptr>
	inline bool __tree_is_left_child(Ptr __x)
	{
		return __x == __x->__parent_->__left_;
	}

	template <class Ptr>
	inline Ptr __tree_max(Ptr __x)
	{
		while (__x->__right_ != nullptr)
			__x = __x->__right_;
		return __x;
	}

	template <class Ptr>
	inline Ptr __tree_min(Ptr __x) 
	{
		while (__x->__left_ != nullptr)
			__x = __x->__left_;
		return __x;
	}

	template <class Ptr>
	inline Ptr __tree_predecessor(Ptr __x)
	{
		if (__x->__right_ != nullptr)
			return ft::__tree_min(__x->__right_);
		return nullptr;
	}

	template <class Ptr>
	inline Ptr __tree_successor(Ptr __x)
	{
		if (__x->__right_ != nullptr)
			return ft::__tree_min(__x->__right_);
		return nullptr;
	}
	
	template <class Ptr>
	inline Ptr __tree_next_iter(Ptr __x)
	{
		if (__x->__right_ != nullptr)
			return ft::__tree_min(__x->__right_);
		while (!ft::__tree_is_left_child(__x))
			__x = __x->__parent_;
		return __x->__parent_;
	}

	template <class Ptr>
	inline Ptr __tree_prev_iter(Ptr __x)
	{
		if (__x->__left_ != nullptr)
			return ft::__tree_max(__x->__left_);
		Ptr __y = __x;
		while (ft::__tree_is_left_child(__y))
			__y = __y->__parent_;
		return __y->__parent_;
	}

	template <class Tp, class NodePtr, class DiffType>
	class __tree_iterator
	{
	public:
		typedef Tp																value_type;
		typedef std::bidirectional_iterator_tag									iterator_category;
		typedef DiffType														difference_type;
		typedef value_type&														reference;
		typedef value_type*														pointer;

		//constractor
		__tree_iterator() : __ptr_(nullptr){}

		reference operator * () const
		{
			return __ptr_->__value_;
		}

		pointer operator -> () const
		{
			return std::addressof(operator*());
		}

		__tree_iterator &operator ++ () 
		{
			__ptr_ = __tree_next_iter(__ptr_);
			return *this;
		}
		
		__tree_iterator operator ++ (int)
		{
			__tree_iterator __t(*this);
			++(*this);
			return __t;
		}

		__tree_iterator &operator -- () 
		{
			__ptr_ = __tree_prev_iter(__ptr_);
			return *this;
		}

		__tree_iterator operator -- (int)
		{
			__tree_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator == (const __tree_iterator &__x, const __tree_iterator &__y)
		{
			return __x.__ptr_ == __y.__ptr_;
		}

		friend bool operator != (const __tree_iterator &__x, const __tree_iterator &__y)
		{
			return !(__x == __y);
		}

	private:
		NodePtr __ptr_;
		explicit __tree_iterator(NodePtr __p)  : __ptr_(__p) {}
		template <class, class, class> friend class __tree;
		template <class, class, class> friend class __tree_const_iterator;
		template <class, class, class, class> friend class map;
		template <class, class, class> friend class set;
	};


	template <class Tp, class NodePtr, class DiffType>
	class __tree_const_iterator
	{
	public:
		typedef Tp																value_type;
		typedef std::bidirectional_iterator_tag									iterator_category;
		typedef DiffType														difference_type;
		typedef const value_type&												reference;
		typedef const value_type*												pointer;
		typedef __tree_iterator<value_type, NodePtr, difference_type> 			__non_const_iterator;
	
	public:
		//constractor
		__tree_const_iterator() : __ptr_(nullptr){}
		__tree_const_iterator(const __non_const_iterator &__p) : __ptr_(__p.__ptr_)
		{}

		reference operator * () const
		{
			return __ptr_->__value_;
		}

		pointer operator -> () const
		{
			return std::addressof(operator*());
		}

		__tree_const_iterator &operator ++ ()
		{
			__ptr_ = __tree_next_iter(__ptr_);
			return *this;
		}

		__tree_const_iterator operator++(int)
		{
			__tree_const_iterator __t(*this);
			++(*this);
			return __t;
		}

		__tree_const_iterator &operator--()
		{
			__ptr_ = __tree_prev_iter(__ptr_);
			return *this;
		}

		__tree_const_iterator operator--(int)
		{
			__tree_const_iterator __t(*this);
			--(*this);
			return __t;
		}

		friend bool operator==(const __tree_const_iterator &__x, const __tree_const_iterator &__y)
		{
			return __x.__ptr_ == __y.__ptr_;
		}

		friend bool operator!=(const __tree_const_iterator &__x, const __tree_const_iterator &__y)
		{
			return !(__x == __y);
		}

	private:
		NodePtr __ptr_;
    	explicit __tree_const_iterator(NodePtr __p) : __ptr_(__p) {}
		template <class, class, class> friend class __tree;
		template <class, class, class, class> friend class  map;
		template <class, class, class> friend class  set;
	};
}

#endif