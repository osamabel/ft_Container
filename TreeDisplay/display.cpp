/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:36:05 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/02 14:35:50 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <locale> 
#include "../Containers/ft_map.hpp"
#include "../Containers/ft_set.hpp"
#include "../Tree/tree_iterator.hpp"

template<class T1, class T>
void getInfo(T1 node, std::vector<T> &data)
{
	static int i;

	if (node)
	{
		node->__depth_ = ++i;
		data.push_back(node);
		node->__passed_ = false;
		if (node->__left_)
			getInfo(node->__left_, data);
		else if (node->__right_)
			getInfo(node->__right_, data);
		else 
		{
			while (node->__parent_ && !node->__passed_ && (!node->__right_ || !node->__right_->__passed_))
			{
				node = node->__parent_;
				i--;
			}
			if (node->__right_ && node->__parent_)
				getInfo(node->__right_, data);
		}
	}
}

template<class T>
bool __comp_map(T &a, T &b)
{
	return (a)->__value_.first > (b)->__value_.first;
}

template<class T1, class T2>
void display(ft::map<T1, T2> &__m)
{

	typedef typename ft::map<T1, T2>::node_pointer				node_pointer;

	std::vector<node_pointer> data;

	getInfo(__m.__root(), data);
	
	sort(data.begin(), data.end(), __comp_map<node_pointer>);

	bool r = false;
	int depth = 0;
		
	for (typename std::vector<node_pointer>::iterator x = data.begin(); x != data.end(); x++)
	{
		for (int i = 0; i <= (*x)->__depth_ + 5; ++i)
		{
			if (r && i == depth - 1 && depth < (*x)->__depth_)
			{
				std::cout << "/";
				r = false;
			}
			if (i < (*x)->__depth_ - 1)
				std::cout << "\t\t";
		}
				
		if ((*x) == (*x)->__parent_->__right_)
		{
			std::cout << " ";
		}
		if ((*x) == (*x)->__parent_->__left_ && (*x)->__parent_->__parent_)
			std::cout << "\\" ;


		// ----------------------------------------------------------------------------- print value
		std::cout << std::setfill('_') << std::right;
		if ((*x)->__is_black_)
			std::cout << std::setw(14) << (*x)->__value_.first;
		else
			std::cout << "\033[1;31m" << std::setw(14) << (*x)->__value_.first << "\033[0m";
		// -----------------------------------------------------------------------------------------------------

		if (r && depth > (*x)->__depth_)
		{
			std::cout << " /";
			r = false;
		}

		if ((*x) == (*x)->__parent_->__right_)
		{
			r = true;
			depth = (*x)->__depth_;
		}
		std::cout << "\n";
	}	
}

template<class T>
bool __comp_set(T &a, T &b)
{
	return (a)->__value_ > (b)->__value_;
}

template<class T1>
void display(ft::set<T1> &__m)
{

	typedef typename ft::set<T1>::node_pointer					node_pointer;

	std::vector<node_pointer> data;

	getInfo(__m.__root(), data);
	
	sort(data.begin(), data.end(), __comp_set<node_pointer>);

	bool r = false;
	int depth = 0;
		
	for (typename std::vector<node_pointer>::iterator x = data.begin(); x != data.end(); x++)
	{
		for (int i = 0; i <= (*x)->__depth_ + 5; ++i)
		{
			if (r && i == depth - 1 && depth < (*x)->__depth_)
			{
				std::cout << "/";
				r = false;
			}
			if (i < (*x)->__depth_ - 1)
				std::cout << "\t\t";
		}
				
		if ((*x) == (*x)->__parent_->__right_)
		{
			std::cout << " ";
		}
		if ((*x) == (*x)->__parent_->__left_ && (*x)->__parent_->__parent_)
			std::cout << "\\" ;


		// ----------------------------------------------------------------------------- print value
		std::cout << std::setfill('_') << std::right;
		if ((*x)->__is_black_)
			std::cout << std::setw(14) << (*x)->__value_;
		else
			std::cout << "\033[1;31m" << std::setw(14) << (*x)->__value_ << "\033[0m";
		// -----------------------------------------------------------------------------------------------------

		if (r && depth > (*x)->__depth_)
		{
			std::cout << " /";
			r = false;
		}

		if ((*x) == (*x)->__parent_->__right_)
		{
			r = true;
			depth = (*x)->__depth_;
		}
		std::cout << "\n";
	}	
}	


// const bd = document.querySelector("body")
// const inpt = document.getElementById("value");

// var i = 0;
// const Interval = setInterval(inserting, 500);
// function inserting()
// {
// 	inpt.value = i;
// 	insert();
// 	i++;
// }
// function stoptime()
// {
// 	clearInterval(Interval)
// }

// bd.addEventListener("click", stoptime);

// https://yongdanielliang.github.io/animation/web/RBTree.html
