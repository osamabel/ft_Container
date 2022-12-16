/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:28:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/02 17:09:56 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void stk_test3()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 3 < push pop top > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
        	std::cout << "\033[34m" << "ft::vector<int> v1 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::vector<int> v2 (3, 100)" << "\033[0m" << std::endl << std::endl;
            
            ft::vector<int> v1 (3, 300);          
            std::vector<int> v2 (3, 200);        

            std::stack<int,ft::vector<int> > s1 (v1);  
            std::stack<int,std::vector<int> > s2 (v2);

        	std::cout << "\033[34m" << "ft::stack<int,ft::vector<int> > s1 (v1) " << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
        	std::cout << "\033[34m" << "ft::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(15);
			s2.push(15);
			std::cout << "\033[34m" << "s1.push(15)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[34m" << "s2.push(15)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(600);
			s2.push(600);
			std::cout << "\033[34m" << "s1.push(600)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[34m" << "s2.push(600)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.pop();
			s2.pop();
			std::cout << "\033[34m" << "s1.pop()" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[34m" << "s2.pop()" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;

        }
        catch(const std::string str)
        {
            std::cerr << str << '\n';
        }
        std::cout << "\033[33m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::cout << "\033[33m" << "ft::vector<int> v1 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "std::vector<int> v2 (3, 100)" << "\033[0m" << std::endl << std::endl;
            
            ft::vector<int> v1 (3, 300);          
            std::vector<int> v2 (3, 200);        

            ft::stack<int,ft::vector<int> > s1 (v1);  
            ft::stack<int,std::vector<int> > s2 (v2);

        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s1 (v1) " << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(15);
			s2.push(15);
			std::cout << "\033[33m" << "s1.push(15)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[33m" << "s2.push(15)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(600);
			s2.push(600);
			std::cout << "\033[33m" << "s1.push(600)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[33m" << "s2.push(600)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.pop();
			s2.pop();
			std::cout << "\033[33m" << "s1.pop()" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[33m" << "s2.pop()" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}