/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:28:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/02 16:12:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void stk_test0()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 0 ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
	{
		ft::stack<int, ft::vector<int> > s;
		s.push(5);
		assert(s.top() == 5);
		s.push(6);
		assert(s.top() == 6);
		s.pop();
		assert(s.top() == 5);
    	std::cout << "testing stack with my vector + top | push | pop\n";
  	}
	{
		ft::stack<int> ss;
		assert(ss.empty());
		ss.push(5);
		assert(!ss.empty());
		ss.pop();
		assert(ss.empty());
		std::cout << "testing stack with my vector + empty\n";
	}
	{
		ft::stack<double, std::vector<double> > s;
		s.push(5);
		assert(s.top() == 5);
		s.push(6);
		assert(s.top() == 6);
		s.pop();
		assert(s.top() == 5);
		std::cout << "testing stack with stl vector + top | push | pop\n";
	}
	{
		ft::stack<int, std::vector<int> > ss;
		assert(ss.empty());
		ss.push(5);
		assert(!ss.empty());
		ss.pop();
		assert(ss.empty());
		std::cout << "testing stack with stl vector + empty\n";
	}
	{
		ft::stack<double, std::list<double> > s;
		s.push(5);
		assert(s.top() == 5);
		s.push(6);
		assert(s.top() == 6);
		s.pop();
		assert(s.top() == 5);
		std::cout << "testing stack with stl list + top | push | pop\n";
	}
	{
		ft::stack<int, std::list<int> > ss;
		assert(ss.empty());
		ss.push(5);
		assert(!ss.empty());
		ss.pop();
		assert(ss.empty());
		std::cout << "testing stack with stl list + empty\n";
	}
}