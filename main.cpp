/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:55:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/22 12:43:49 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include <vector>
#include <list>
// #include "Containers/ft_vector.hpp"

#include <iterator>
#include <iostream>

void p(std::vector<int>::iterator itr1, std::vector<int>::iterator itr2)
{
	while (itr1 != itr2)
		std::cout << *itr1++ << ' ';
 	std::cout << '\n';
	
}
void pl(std::list<int>::iterator itr1, std::list<int>::iterator itr2)
{
	while (itr1 != itr2)
		std::cout << *itr1++ << ' ';
 	std::cout << '\n';
}
int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.push_back(14);
 
 
    p(v.begin(), v.end());
 	std::cout << "------------------------" << '\n';

	
	std::vector<int>::iterator itr1 = v.begin() + 3;
	std::vector<int>::iterator itr2 = v.begin() + 8;
	std::vector<int>::iterator itr3;
 	std::cout << *itr1 << '\n';
 	std::cout << *itr2 << '\n';

	
 	std::cout << "------------------------" << '\n';
	itr3 = v.erase(itr1, itr2);

    p(v.begin(), v.end());
 	std::cout << *itr3 << '\n';

}