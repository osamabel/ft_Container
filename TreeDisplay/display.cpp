/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:36:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/21 18:43:11 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <locale> 
#include "../Containers/ft_map.hpp"
#include "../Tree/tree_iterator.hpp"


typedef ft::map<int, char>::node_pointer   			node_pointer;
typedef ft::map<int, char>::node					node;

typedef struct s_data{

	node_pointer	__node;				//	node
	char			__direction;		//	left or right
	int				__depth;			//	hight of this node
}	t_data;


void getInfo(node_pointer node, std::vector<t_data> &data)
{
	static int i;
	t_data info;

	if (node)
	{

		info.__node = node;
		if (node->__parent_->__parent_ == nullptr)
			info.__direction = 'r';
		else if (ft::__tree_is_left_child(node))
			info.__direction = '<';
		else
			info.__direction = '>';
		info.__depth = ++i;
		data.push_back(info);

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

bool compareByfirst(const t_data &a, const t_data &b)
{
	return a.__node->__value_.first > b.__node->__value_.first;
}

void display(ft::map<int, char> &__m)
{

	std::vector<t_data> data;
	node_pointer root = __m.__root();

	getInfo(root, data);
	sort(data.begin(), data.end(), compareByfirst);
	bool r = false;
	int depth = 0;
	for (std::vector<t_data>::iterator x = data.begin(); x != data.end(); x++)
	{
		for (int i = 0; i <= x->__depth + 5; ++i)
		{
			if (r && i == depth - 1 && depth < x->__depth)
			{
				std::cout << "/";
				r = false;
			}
			if (i < x->__depth - 1)
				std::cout << "\t\t";
		}
				
		if (x->__node == x->__node->__parent_->__right_)
		{
			std::cout << " ";
		}
		if (x->__node == x->__node->__parent_->__left_ && x->__node->__parent_->__parent_)
			std::cout << "\\" ;


		// ----------------------------------------------------------------------------- print value
		std::cout << std::setfill('_') << std::right;
		if (x->__node->__is_black_)
			std::cout << std::setw(14) << std::to_string(x->__node->__value_.first);
		else
			std::cout << "\033[1;31m" << std::setw(14) << std::to_string(x->__node->__value_.first) << "\033[0m";
		// -----------------------------------------------------------------------------------------------------

		if (r && depth > x->__depth)
		{
			std::cout << " /";
			r = false;
		}

		if (x->__node == x->__node->__parent_->__right_)
		{
			r = true;
			depth = x->__depth;
		}
		std::cout << "\n";
	}	
}	
