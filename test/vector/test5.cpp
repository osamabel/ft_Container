/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void v_test5()
{
    std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 5 < reserve > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        int value = 5;
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(value);
        	std::cout << "\033[34m" << "std::vector<int> v(5) :" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "vector => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;
            
        	std::cout << "\033[34m" << "add [0 - 5[ : " << "\033[0m" << std::endl;
            for (int i = 0; i < value ; i++)
			{
                v.push_back(i);
            }
        	std::cout << "\033[34m" << "vector => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;
            
            v.reserve(15);
        	std::cout << "\033[34m" << "std::vector<int> v(5 * 3) :" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "vector => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;


            v.reserve(5);
        	std::cout << "\033[34m" << "std::vector<int> v(5) :" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "vector => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;
    
            
            v.reserve(20);
        	std::cout << "\033[34m" << "std::vector<int> v(20) :" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "vector => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v(value);
        	std::cout << "\033[32m" << "ft::vector<int> v(5) :" << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "vector => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;
            
        	std::cout << "\033[32m" << "add [0 - 5[ : " << "\033[0m" << std::endl;
            for (int i = 0; i < value ; i++)
			{
                v.push_back(i);
            }
        	std::cout << "\033[32m" << "vector => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;
            
            v.reserve(15);
        	std::cout << "\033[32m" << "ft::vector<int> v(5 * 3) :" << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "vector => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;


            v.reserve(5);
        	std::cout << "\033[32m" << "ft::vector<int> v(5) :" << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "vector => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;
    
            
            v.reserve(20);
        	std::cout << "\033[32m" << "ft::vector<int> v(20) :" << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "vector => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
			{
			    std::cout << "\t" << *i;
			}
            std::cout << '\t' << "capacity = " << v.capacity() << std::endl << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

}