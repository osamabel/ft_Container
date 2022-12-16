/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:36:05 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/16 23:25:42 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iostream>
#include "../Containers/ft_map.hpp"

typedef ft::map<int, char>::node_pointer   			node_pointer;
typedef ft::map<int, char>::node					node;

typedef struct s_data{

	node_pointer	__node;				//	node
	char			__direction;		//	left or right
	int				__nil;				//	number of nil under node
	int				__depth;			//	hight of this node
}	t_data;


int nilNumber (node_pointer node)
{
    if(node == nullptr)
        return 0; 
    if(node->__left_ == nullptr && node->__right_ == nullptr) 
        return 2;         
    else if(node->__left_ != nullptr && node->__right_ == nullptr) 
        return 1;
    else if(node->__left_ == nullptr && node->__right_ != nullptr) 
        return 1;         
    else
        return nilNumber(node->__left_)+ nilNumber(node->__right_); 
}

void getInfo(node_pointer node, std::vector<t_data> &data)
{
	static int i;
	if (node)
	{
		t_data info;
		info.__node = node;
		if (node->__parent_->__parent_ == nullptr)
			info.__direction = 'r';
		else if (node == node->__parent_->__left_)
			info.__direction = '<';
		else if (node == node->__parent_->__right_)
			info.__direction = '>';
		// info.__nil = 0;
		info.__nil = nilNumber(node);
		info.__depth = ++i;
		data.push_back(info);
	
		if (node->__left_)
			getInfo(node->__left_, data);
		else if (node->__right_)
			getInfo(node->__right_, data);
		else 
		{
			if (node == node->__parent_->__left_)
			{
				node = node->__parent_;
				i--;
			}
			else
			{
				while (node == node->__parent_->__right_)
				{
					node = node->__parent_;
					i--;
				}
				node = node->__parent_;i--;
			}
			if (node->__right_)
				getInfo(node->__right_, data);
			else
				getInfo(node->__parent_, data);
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

	for (std::vector<t_data>::iterator x = data.begin(); x != data.end(); x++)
	{
		std::cout << "depth = " << x->__depth << '\t' <<
		"direction = " << x->__direction << '\t' <<
		"node.value.first = " << x->__node->__value_.first << '\t' <<
		"nil = " << x->__nil << '\n';
	}
	sort(data.begin(), data.end(), compareByfirst);
	std::cout << "===========================\n";
	for (std::vector<t_data>::iterator x = data.begin(); x != data.end(); x++)
	{
		std::cout << "depth = " << x->__depth << '\t' <<
		"direction = " << x->__direction << '\t' <<
		"node.value.first = " << x->__node->__value_.first << '\t' <<
		"nil = " << x->__nil << '\n';
	}
	std::cout << "===========================\n";
	for (std::vector<t_data>::iterator x = data.begin(); x != data.end(); x++)
	{

		for (int i = 1; i < x->__depth; ++i)
			std::cout << "\t";
		if (x->__direction == '<')
			std::cout << "|_" ;
		if (x->__direction == '>')
			std::cout << " _" ;
		if (x->__node->__is_black_)
			std::cout << x->__node->__value_.first;
		else
			std::cout << "\033[1;31m" << x->__node->__value_.first <<"\033[0m";
		if (x->__direction == 'r')
			std::cout << '_' << '\n';
		else
			std::cout << '\n';
	}
		
}