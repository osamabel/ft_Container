/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/27 21:34:00 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void test0()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 0 < constructors , iterators > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
       	std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v1;
            std::vector<int> v2(5, 5);
            std::vector<int> v3(v2.begin(), v2.end());
            std::vector<int> v4(v3);
            

            std::cout << "\033[34m" << "-------------- std::vector<int> v1 --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v1.begin() ; it != v1.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[34m" << "-------------- std::vector<int> v1 < reverse > --------------"  << "\033[0m"<< std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::reverse_iterator it = v1.rbegin() ; it != v1.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "\033[34m" << "-------------- std::vector<int> v2(5, 5) --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v2.begin() ; it != v2.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[34m" << "-------------- std::vector<int> v2(5, 5) < reverse > --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::reverse_iterator it = v2.rbegin() ; it != v2.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "\033[34m" << "-------------- std::vector<int> v3(v2.begin(), v2.end()) --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v3.begin() ; it != v3.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[34m" << "-------------- std::vector<int> v3(v2.begin(), v2.end()) < reverse > --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::reverse_iterator it = v3.rbegin() ; it != v3.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "\033[34m" << "-------------- std::vector<int> v4(v3) --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v4.begin() ; it != v4.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[34m" << "-------------- std::vector<int> v4(v3) < reverse > --------------" << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::reverse_iterator it = v4.rbegin() ; it != v4.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[33m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v1;
            ft::vector<int> v2(6, 5);
            ft::vector<int> v3(v2.begin(), v2.end());
            ft::vector<int> v4(v3);
            

            std::cout << "\033[33m" << "-------------- ft::vector<int> v1 --------------"  << "\033[0m"<< std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v1.begin() ; it != v1.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[33m" << "-------------- ft::vector<int> v1 < reverse > --------------"  << "\033[0m"<< std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::reverse_iterator it = v1.rbegin() ; it != v1.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "\033[33m" << "-------------- ft::vector<int> v2(5, 5) --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v2.begin() ; it != v2.end(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[33m" << "-------------- ft::vector<int> v2(5, 5) < reverse > --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::reverse_iterator it = v2.rbegin() ; it != v2.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "\033[33m" << "-------------- ft::vector<int> v3(v2.begin(), v2.end()) --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v3.begin() ; it != v3.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[33m" << "-------------- ft::vector<int> v3(v2.begin(), v2.end()) < reverse > --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::reverse_iterator it = v3.rbegin() ; it != v3.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;

            std::cout << "\033[33m" << "-------------- ft::vector<int> v4(v3) --------------"  << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v4.begin() ; it != v4.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl;
            
            std::cout << "\033[33m" << "-------------- ft::vector<int> v4(v3) < reverse > --------------" << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[33m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::reverse_iterator it = v4.rbegin() ; it != v4.rend(); it++)
                std::cout << "\t" << *it;
            std::cout << std::endl;
            std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}