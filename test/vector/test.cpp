/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/03 12:38:34 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void v_test0()
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

void v_test1()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 1 < max_size > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(10, 3);
            std::cout << std::endl << "\033[34m" << "v.max_size() : " << "\033[0m";
            std::cout << v.max_size() << std::endl << std::endl;

            std::cout << std::endl << "\033[34m" << "std::vector<int> v(10, 3)" << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            
            // * resize
            std::cout << std::endl << "\033[34m" << "size() / capacity() " << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            v.resize(5);
            std::cout << std::endl << "\033[34m" << "v.resize(5) " << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;  
            std::cout << std::endl << "\033[34m" << "size() / capacity() " << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            
            v.resize(11);
            std::cout << std::endl << "\033[34m" << "v.resize(11) " << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[34m" << "Vector => " << "\033[0m";
            for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl << "\033[34m" << "size() / capacity() " << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v(10, 3);
            std::cout << std::endl << "\033[32m" << "v.max_size() : " << "\033[0m";
            std::cout << v.max_size() << std::endl;

            std::cout << std::endl << "\033[32m" << "ft::vector<int> v(10, 3)" << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[32m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v.begin() ; it != v.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            
            // * resize
            std::cout << std::endl << "\033[32m" << "size() / capacity() " << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            v.resize(5);
            std::cout << std::endl << "\033[32m" << "v.resize(5) " << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[32m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v.begin() ; it != v.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl << "\033[32m" << "size() / capacity() " << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            
            v.resize(11);
            std::cout << std::endl << "\033[32m" << "v.resize(11) " << "\033[0m" << std::endl;
            std::cout << std::endl << "\033[32m" << "Vector => " << "\033[0m";
            for (ft::vector<int>::iterator it = v.begin() ; it != v.end(); it++)
                std::cout << "\t" << *it ;
            std::cout << std::endl;
            std::cout << std::endl << "\033[32m" << "size() / capacity() " << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void v_test2()
{
	  std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 2 < size , capacity > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        int values = 10;
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;

            // * size & capacity
            for (int i = 0; i < values ; i++){
                std::cout << "size = " << v.size() << " | ";
                std::cout << "capacity = " << v.capacity() << std::endl;
                v.push_back(i);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;

            // * size & capacity
            for (int i = 0; i < values ; i++){
                std::cout << "size = " << v.size() << " | ";
                std::cout << "capacity = " << v.capacity() << std::endl;
                v.push_back(i);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void v_test3()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 3 < resize > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        int values = 10;
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;

            for (int i = 0; i < values ; i++)
                v.push_back(i);
                
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;

            v.resize (0);
            std::cout << std::endl << "\033[34m" << "v.resize (0)" << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            
            v.resize (17);
            std::cout << std::endl << "\033[34m" << "v.resize (17)" << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;

            v.resize (70);
            std::cout << std::endl << "\033[34m" << "v.resize (70)" << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;

            for (int i = 0; i < values ; i++)
                v.push_back(i);

            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            
            v.resize (0);
            std::cout << std::endl << "\033[32m" << "v.resize (0)" << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
            
            v.resize (17);
            std::cout << std::endl << "\033[32m" << "v.resize (17)" << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;

            v.resize (70);
            std::cout << std::endl << "\033[32m" << "v.resize (70)" << "\033[0m" << std::endl;
            std::cout << "size = " << v.size() << std::endl;
            std::cout << "capacity = " << v.capacity() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
void v_test4()
{
	 std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 4 < empty > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        int values = 10;
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(5);
        	std::cout << "\033[34m" << "std::vector<int> v(5) : " << "\033[0m" << std::endl;

			if (v.empty())
            	std::cout << "the vector is empty " << std::endl;
			else
            	std::cout << "the vector isn't empty " << std::endl;
			std::cout << std::endl;
            
            v.resize(0);
        	std::cout << "\033[34m" << "vresize(0) : " << "\033[0m" << std::endl;
			if (v.empty())
            	std::cout << "the vector is empty " << std::endl;
			else
            	std::cout << "the vector isn't empty " << std::endl;
			std::cout << std::endl;
            
        	std::cout << "\033[34m" << "fill vector with [1 - 9] : " << "\033[0m" << std::endl;
            for (int i = 0; i < values ; i++){
                v.push_back(i);
            }
        	std::cout << "\033[34m" << "vector => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin() ; i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << std::endl;
			if (v.empty())
            	std::cout << "the vector is empty " << std::endl;
			else
            	std::cout << "the vector isn't empty " << std::endl;
			std::cout << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v(5);
        	std::cout << "\033[32m" << "ft::vector<int> v(5) : " << "\033[0m" << std::endl;

			if (v.empty())
            	std::cout << "the vector is empty " << std::endl;
			else
            	std::cout << "the vector isn't empty " << std::endl;
			std::cout << std::endl;
            
            v.resize(0);
        	std::cout << "\033[32m" << "vresize(0) : " << "\033[0m" << std::endl;
			if (v.empty())
            	std::cout << "the vector is empty " << std::endl;
			else
            	std::cout << "the vector isn't empty " << std::endl;
			std::cout << std::endl;
            
        	std::cout << "\033[32m" << "fill vector with [1 - 9] : " << "\033[0m" << std::endl;
            for (int i = 0; i < values ; i++){
                v.push_back(i);
            }
        	std::cout << "\033[32m" << "vector => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin() ; i < v.end() ; i++)
                std::cout << "\t" << *i;
			std::cout << std::endl;

			if (v.empty())
            	std::cout << "the vector is empty " << std::endl;
			else
            	std::cout << "the vector isn't empty " << std::endl;
			std::cout << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

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

void v_test6()
{
  std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 6 < operator [] > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
       std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(10);

            std::cout << "\033[34m" << "std::vector<int> v(10) : " << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "v[100] = 15 : " << "\033[0m" << std::endl;
            v[100] = 15;
            std::cout << v[100] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v(10);
            std::cout << "\033[32m" << "std::vector<int> v(10) : " << "\033[0m" << std::endl;
            std::cout << "\033[32m" << "v[100] = 15 : " << "\033[0m" << std::endl;
            v[100] = 15;
            std::cout << v[100] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }
}

void v_test7()
{
  	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 7 < at > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(10);
            std::cout << "\033[34m" << "std::vector<int> v(10) : " << "\033[0m" << std::endl;

            v.at(8) = 15;
            std::cout << "v.at(8) : " << v.at(8) << std::endl;
            std::cout << "v.at(9) : " << v.at(9) << std::endl;
            std::cout << "v.at(10) : " << v.at(10) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v(10);
            std::cout << "\033[32m" << "std::vector<int> v(10) : " << "\033[0m" << std::endl;

            v.at(8) = 15;
            std::cout << "v.at(8) : " << v.at(8) << std::endl;
            std::cout << "v.at(9) : " << v.at(9) << std::endl;
            std::cout << "v.at(10) : " << v.at(10) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}
void v_test8()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 8 < front , back > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;

            v.push_back(11);
        	std::cout << "\033[34m" << "v => [11]" << "\033[0m" << std::endl;
            std::cout << "front = " << v.front() << std::endl;
            std::cout << "back = " << v.back() << std::endl << std::endl;

            v.push_back(5);
        	std::cout << "\033[34m" << "v => [11, 5]" << "\033[0m" << std::endl;
            std::cout << "front = " << v.front() << std::endl;
            std::cout << "back = " << v.back() << std::endl << std::endl;

            v.front() = 1;
            v.back() = 15;
        	std::cout << "\033[34m" << "v.front() = 1 , v.back() = 15" << "\033[0m" << std::endl;
            std::cout << "front = " << v.front() << std::endl;
            std::cout << "back = " << v.back() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;

            v.push_back(11);
        	std::cout << "\033[34m" << "v => [11]" << "\033[0m" << std::endl;
            std::cout << "front = " << v.front() << std::endl;
            std::cout << "back = " << v.back() << std::endl << std::endl;

            v.push_back(5);
        	std::cout << "\033[34m" << "v => [11, 5]" << "\033[0m" << std::endl;
            std::cout << "front = " << v.front() << std::endl;
            std::cout << "back = " << v.back() << std::endl << std::endl;

            v.front() = 1;
            v.back() = 15;
        	std::cout << "\033[34m" << "v.front() = 1 , v.back() = 15" << "\033[0m" << std::endl;
            std::cout << "front = " << v.front() << std::endl;
            std::cout << "back = " << v.back() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void v_test9()
{
	 std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 9 < assign > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(10);
        	std::cout << "\033[34m" << "std::vector<int> v(10)" << "\033[0m" << std::endl;

        	std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            
            v.assign(15, 10);
        	std::cout << "\033[34m" << "v.assign(15, 10) : " << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
          
            std::vector<int> v2;
        	std::cout << "\033[34m" << "std::vector<int> v2" << "\033[0m" << std::endl;
            v2.push_back(5);
        	std::cout << "\033[34m" << "v2.push_back(5)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;
        	std::cout << "\033[34m" << "v2.assign(v.begin() + 1, v.end() - 1)" << "\033[0m" << std::endl;
            v2.assign(v.begin() + 1, v.end() - 1);
        	std::cout << "\033[34m" << "v2 =>" << "\033[0m";
            for (std::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            // ft::vector<int> v(10);
            ft::vector<int> v(10);
        	std::cout << "\033[32m" << "ft::vector<int> v(10)" << "\033[0m" << std::endl;

        	std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            
			//v.assign(15, 10)
            v.assign(15, 10);
        	std::cout << "\033[32m" << "v.assign(15, 10) : " << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
          
            // ft::vector<int> v2;
            ft::vector<int> v2;
        	std::cout << "\033[32m" << "ft::vector<int> v2" << "\033[0m" << std::endl;
            v2.push_back(5);
        	std::cout << "\033[32m" << "v2.push_back(5)" << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "v2 =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;
        	std::cout << "\033[32m" << "v2.assign(v.begin() + 1, v.end() - 1)" << "\033[0m" << std::endl;
			
			//v2.assign(v.begin() + 1, v.end() - 1)
            v2.assign(v.begin() + 1, v.end() - 1);
        	std::cout << "\033[32m" << "v2 =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;		
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }  
    }
}
void v_test10()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 10 < push_back > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        int values = 10;
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;
			std::cout << "\033[34m" << "std::vector<int> v : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "fill [0 - 9] : " << "\033[0m" << std::endl;
            for (int i = 0; i < values ; i++)
                v.push_back(i);
            
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i != v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout<< std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;
			std::cout << "\033[32m" << "ft::vector<int> v : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "fill [0 - 9] : " << "\033[0m" << std::endl;
            for (int i = 0; i < values ; i++)
                v.push_back(i);
            
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i != v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout<< std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void v_test11()
{
std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 11 < pop_back > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        int value = 5;
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;
			std::cout << "\033[34m" << "std::vector<int> v : " << "\033[0m" << std::endl;

            for (int i = 0; i < value ; i++){
                v.push_back(i);
            }
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
			std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            
            v.pop_back();
			std::cout << "\033[34m" << "v.pop_back() : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
			std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            std::cout  << "\033[34m" << "*(v.end()) = " << "\033[0m" << *(v.end()) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;
			std::cout << "\033[32m" << "ft::vector<int> v : " << "\033[0m" << std::endl;

            for (int i = 0; i < value ; i++){
                v.push_back(i);
            }
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
			std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            
            v.pop_back();
			std::cout << "\033[32m" << "v.pop_back() : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
			std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            std::cout  << "\033[32m" << "*(v.end()) = " << "\033[0m" << *(v.end()) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        } 
    }
}

void v_test12()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 12 < insert > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
			
			std::cout << "\033[34m" << " don't foregt : vct.insert(vct3.begin(), *val) // val is reference from vector!! " << "\033[0m" << std::endl;
            std::vector<int> v (3,100);
            std::vector<int>::iterator it;

			std::cout << "\033[34m" << "std::vector<int> v (3,100) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
                    
            it = v.begin();
            it = v.insert ( it , 200 );
			std::cout << "\033[34m" << "it = v.insert ( v.begin() , 200 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            
            it = v.begin() + 2;
            v.insert ( it , 6 , 10 );
			std::cout << "\033[34m" << "it = v.insert ( v.begin() + 2, 6, 10 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << "\t" << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl << std::endl;

			std::cout << "\033[34m" << "myarray [] = { 501,502,503 }" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v.insert (v.begin() + 1, myarray, myarray+3)" << "\033[0m" << std::endl;
            int myarray [] = { 501,502,503 };
			std::cout << "\033[34m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 1, myarray, myarray+3);
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

			std::cout << "\033[34m" << "With enough CAPACIRY !! " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v.insert (v.begin() + 7, myarray, myarray+3)" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 7, myarray, myarray+3);
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v (3,100);
            ft::vector<int>::iterator it;

			std::cout << "\033[32m" << "ft::vector<int> v (3,100) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
                    
            it = v.begin();
            it = v.insert ( it , 200 );
			std::cout << "\033[32m" << "it = v.insert ( v.begin() , 200 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            
            it = v.begin() + 2;
            v.insert ( it , 6 , 10 );
			std::cout << "\033[32m" << "it = v.insert ( v.begin() + 2, 6, 10 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << "\t" << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl << std::endl;

			std::cout << "\033[32m" << "myarray [] = { 501,502,503 }" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v.insert (v.begin() + 1, myarray, myarray+3)" << "\033[0m" << std::endl;
            int myarray [] = { 501,502,503 };
			std::cout << "\033[32m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 1, myarray, myarray+3);
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

			std::cout << "\033[32m" << "With enough CAPACIRY !! " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v.insert (v.begin() + 7, myarray, myarray+3)" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 7, myarray, myarray+3);
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}


void v_test13()
{
std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 13 < erase > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;
            std::vector<int>::iterator it;
			std::cout << "\033[34m" << "std::vector<int> v : " << "\033[0m" << std::endl;

            for (int i=1; i<=10; i++)
                v.push_back(i);
			std::cout << "\033[34m" << "fill v [1 - 10]" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
            
            it = v.erase (v.begin() + 5);
			std::cout << "\033[34m" << "v.erase (v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

            it = v.erase (v.begin(),v.begin() + 2);
			std::cout << "\033[34m" << "v.erase(v.begin(),v.begin() + 2) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
                
            it = v.erase (v.begin() + 2,v.begin() + 5);
			std::cout << "\033[34m" << "v.erase (v.begin() + 2,v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;
            ft::vector<int>::iterator it;
			std::cout << "\033[32m" << "ft::vector<int> v : " << "\033[0m" << std::endl;

            for (int i=1; i<=10; i++)
                v.push_back(i);
			std::cout << "\033[32m" << "fill v [1 - 10]" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
            
            it = v.erase (v.begin() + 5);
			std::cout << "\033[32m" << "v.erase (v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

            it = v.erase (v.begin(),v.begin() + 2);
			std::cout << "\033[32m" << "v.erase(v.begin(),v.begin() + 2) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
                
            it = v.erase (v.begin() + 2,v.begin() + 5);
			std::cout << "\033[32m" << "v.erase (v.begin() + 2,v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
void v_test14()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 14 < swap > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> foo (3,100);
            std::vector<int> bar (5,200);

			std::cout << "\033[34m" << "std::vector<int> foo (3,100) > [100 , 100 , 100] " << "\033[0m" << std::endl;
            std::cout << "foo size = " << foo.size() << std::endl;
            std::cout << "foo capacity = " << foo.capacity() << std::endl;
            std::cout << "foo addr  = " << &(*foo.begin()) << std::endl << std::endl;
			std::cout << "\033[34m" << "std::vector<int> bar (5,200) > [200 , 200 , 200 , 200 , 200] " << "\033[0m" << std::endl;
            std::cout << "bar size = " << bar.size() << std::endl;
            std::cout << "bar capacity = " << bar.capacity() << std::endl;
            std::cout << "bar addr  = " << &(*bar.begin()) << std::endl << std::endl;
           
		    foo.swap(bar);
			std::cout << "\033[34m" << ")===> foo.swap(bar) : " << "\033[0m" << std::endl << std::endl;
			std::cout << "\033[34m" << "foo =>" << "\033[0m";
			for (std::vector<int>::iterator i = foo.begin(); i < foo.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
            std::cout << "foo size = " << foo.size() << std::endl;
            std::cout << "foo capacity = " << foo.capacity() << std::endl;
            std::cout << "foo addr  = " << &(*foo.begin()) << std::endl << std::endl;

			std::cout << "\033[34m" << "bar =>" << "\033[0m";
			for (std::vector<int>::iterator i = bar.begin(); i < bar.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
            std::cout << "bar size = " << bar.size() << std::endl;
            std::cout << "bar capacity = " << bar.capacity() << std::endl;
            std::cout << "bar addr  = " << &(*bar.begin()) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> foo (3,100);
            ft::vector<int> bar (5,200);

			std::cout << "\033[32m" << "ft::vector<int> foo (3,100) > [100 , 100 , 100] " << "\033[0m" << std::endl;
            std::cout << "foo size = " << foo.size() << std::endl;
            std::cout << "foo capacity = " << foo.capacity() << std::endl;
            std::cout << "foo addr  = " << &(*foo.begin()) << std::endl << std::endl;
			std::cout << "\033[32m" << "ft::vector<int> bar (5,200) > [200 , 200 , 200 , 200 , 200] " << "\033[0m" << std::endl;
            std::cout << "bar size = " << bar.size() << std::endl;
            std::cout << "bar capacity = " << bar.capacity() << std::endl;
            std::cout << "bar addr  = " << &(*bar.begin()) << std::endl << std::endl;
           
		    foo.swap(bar);
			std::cout << "\033[32m" << ")===> foo.swap(bar) : " << "\033[0m" << std::endl << std::endl;
			std::cout << "\033[32m" << "foo =>" << "\033[0m";
			for (ft::vector<int>::iterator i = foo.begin(); i < foo.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
            std::cout << "foo size = " << foo.size() << std::endl;
            std::cout << "foo capacity = " << foo.capacity() << std::endl;
            std::cout << "foo addr  = " << &(*foo.begin()) << std::endl << std::endl;

			std::cout << "\033[32m" << "bar =>" << "\033[0m";
			for (ft::vector<int>::iterator i = bar.begin(); i < bar.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
            std::cout << "bar size = " << bar.size() << std::endl;
            std::cout << "bar capacity = " << bar.capacity() << std::endl;
            std::cout << "bar addr  = " << &(*bar.begin()) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }    
    }
}

void v_test15()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 15 < clear > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;
            v.push_back (100);
            v.push_back (200);
            v.push_back (300);
			std::cout << "\033[34m" << "std::vector<int> v => [ 100 , 200 , 300 ]" << "\033[0m" << std::endl;

			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;

            v.clear();
			std::cout << "\033[34m" << "v.clear() : " << "\033[0m" << std::endl;
            std::cout << std::endl;
			std::cout << "\033[34m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[34m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;

            v.push_back (1101);
            v.push_back (2202);
			
			std::cout << "\033[34m" << "push (1101), (2202)" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
			
			std::cout << "\033[34m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[34m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;
            v.push_back (100);
            v.push_back (200);
            v.push_back (300);
			std::cout << "\033[32m" << "ft::vector<int> v => [ 100 , 200 , 300 ]" << "\033[0m" << std::endl;

			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
            v.clear();
			std::cout << "\033[32m" << "v.clear() : " << "\033[0m" << std::endl;
            std::cout << std::endl;
			std::cout << "\033[32m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[32m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;

            v.push_back (1101);
            v.push_back (2202);
			
			std::cout << "\033[32m" << "push (1101), (2202)" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
			
			std::cout << "\033[32m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[32m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
void v_test16()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 16 < non-member functions > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
			std::cout << "\033[34m" << "std::vector<int> foo (3,100) > [ 100 , 100 , 100 ]" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "std::vector<int> bar (2,200) > [ 200 , 200 ]" << "\033[0m" << std::endl;
            std::vector<int> foo (3,100); 
            std::vector<int> bar (2,200); 

			std::cout << "\033[34m" << "[ foo == bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo == bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo != bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo != bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo < bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo < bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo > bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo > bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo <= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo <= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo >= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo >= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;

            std::cout << std::endl;
            foo.swap(bar);
			std::cout << "\033[34m" << ")=======> foo.swap(bar)"<< "\033[0m" << std::endl;
			std::cout << "\033[34m" << "[ foo == bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo == bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo != bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo != bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo < bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo < bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo > bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo > bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo <= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo <= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ foo >= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo >= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
			std::cout << "\033[32m" << "ft::vector<int> foo (3,100) > [ 100 , 100 , 100 ]" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "ft::vector<int> bar (2,200) > [ 200 , 200 ]" << "\033[0m" << std::endl;
            ft::vector<int> foo (3,100); 
            ft::vector<int> bar (2,200); 

			std::cout << "\033[32m" << "[ foo == bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo == bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo != bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo != bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo < bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo < bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo > bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo > bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo <= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo <= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo >= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo >= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;

            std::cout << std::endl;
            foo.swap(bar);
			std::cout << "\033[32m" << ")=======> foo.swap(bar)"<< "\033[0m" << std::endl;
			std::cout << "\033[32m" << "[ foo == bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo == bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo != bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo != bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo < bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo < bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo > bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo > bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo <= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo <= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[32m" << "[ foo >= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            (foo >= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }   
}



void v_test17()
{
    ft::vector<int>::iterator it_vi;
    ft::vector<int> vector_int;
	srand(time(NULL));
	for (int i = 0; i < COUNT; i++)
		vector_int.push_back(rand() % COUNT);
    {
        ft::vector<int> vector_tmp_int(vector_int.begin(), vector_int.end());

        if (vector_int.size() != vector_tmp_int.size())
            std::cerr << "error: vector construction with ranges failed!!\n";
        for (int i = 0; i < COUNT; i++)
        {
            if (vector_int[i] != vector_tmp_int[i])
                std::cerr << "error: vector construction with ranges failed!!\n";
            vector_tmp_int.pop_back();
        }
        if (!vector_tmp_int.empty())
            std::cerr << "error: this vector should be empty!!\n";
    }
    {
        ft::vector<int> vector_tmp_int;

        vector_tmp_int = vector_int;
        if (vector_int.size() != vector_tmp_int.size())
            std::cerr << "error: vector assign failed!!\n";
        for (int i = 0; i < COUNT; i++)
        {
            if (vector_int[i] != vector_tmp_int[i])
                std::cerr << "error: vector assign failed!!\n";
        }
        vector_tmp_int.resize(0, 0);
        if (!vector_tmp_int.empty())
            std::cerr << "error: this vector should be empty!!\n";
    }
	
    {
			ft::vector<int> vector_tmp_int;
			int *arr;

			arr = vector_int.data();
			vector_tmp_int.resize(vector_int.size());

			it_vi = vector_tmp_int.begin();
			ft::swap(vector_int, vector_tmp_int);
			ft::vector<int>::iterator it_vic2 = vector_int.end();
			ft::vector<int>::const_iterator it_vic = vector_int.end();
			if (it_vic == it_vic2){}
			if (it_vi == it_vic2){}
			if (it_vic == it_vi){}
			if (it_vi == it_vic){}

		
			for (; it_vi != it_vic; ++it_vi, ++arr)
				*it_vi = *arr;

			vector_tmp_int.erase(vector_tmp_int.begin() + (COUNT / 2), vector_tmp_int.end());
			vector_tmp_int.insert(vector_tmp_int.end(), vector_int.begin() + (COUNT / 2), vector_int.end());
			for (int i = 0; i < COUNT; i++)
			{
				if (vector_int[i] != vector_tmp_int[i])
					std::cerr << "error: vector erase/insert failed!!\n";
			}
    }

    {
        ft::vector<int> vector_tmp_int(vector_int.begin(), vector_int.end());

        int var_count = COUNT;

        for (int i = 0; i < var_count; i++)
        {
            if (vector_tmp_int.at(i) > COUNT - 100)
            {
                vector_tmp_int.erase(vector_tmp_int.begin() + i);
                --var_count;
            }
        }
        std::cout << "VECTOR CONTENT : " << std::endl;
        std::cout << "*****************" << std::endl;
        for (it_vi = vector_tmp_int.begin(); it_vi != vector_tmp_int.end(); ++it_vi)
            std::cout << *it_vi << ' ';

        std::cout << std::endl;
        std::cout << "VECTOR SIZE : " << std::endl;
        std::cout << "*****************" << std::endl;
        std::cout << vector_tmp_int.size() << std::endl;
    }
    ft::vector<Buffer> vector_buffer;
    for (int i = 0; i < COUNT; i++)
        vector_buffer.push_back(Buffer(rand() % COUNT));
    {
        ft::vector<Buffer> vectro_tmp_buf(vector_buffer.begin(), vector_buffer.end());

        if (vector_buffer.size() != vectro_tmp_buf.size())
            std::cerr << "error: vector construction with ranges failed!!\n";
        for (int i = 0; i < COUNT; i++)
        {
            if (vector_buffer[i] != vectro_tmp_buf[i])
                std::cerr << "error: vector construction with ranges failed!!\n";
        }
        vectro_tmp_buf.clear();
        if (!vectro_tmp_buf.empty())
            std::cerr << "error: this vector should be empty!!\n";
    }
    {
        ft::vector<int> vector_tmp_int;

        vector_tmp_int = vector_int;

        ft::swap(vector_int, vector_tmp_int);
        if (vector_tmp_int == vector_int)
            std::cout << "comp eq\n";
        vector_tmp_int.pop_back();
        if (vector_tmp_int < vector_int)
            std::cout << "comp smaller\n";
        vector_int.pop_back();
        vector_int.pop_back();
        if (vector_tmp_int > vector_int)
            std::cout << "comp greater\n";
    }
    {
        try
        {
            vector_int.at(COUNT);
        }
        catch(...)
        {
            std::cout << "vector error at" << '\n';
        }
        
    }
    std::cout << "abc struct max size:" << ft::vector<Buffer>().max_size() << std::endl;
    std::cout << "Float max size:" << ft::vector<float>().max_size() << std::endl;
    std::cout << "Long max size:" << ft::vector<long>().max_size() << std::endl;
    std::cout << "Int max size:" << ft::vector<int>().max_size() << std::endl;
    std::cout << "Short max size:" << ft::vector<short>().max_size() << std::endl;
    std::cout << "Char max size:" << ft::vector<char>().max_size() << std::endl;
    {
        int *arr;

        arr = vector_int.get_allocator().allocate(7);

        for (int i = 0; i < 7; i++) 
            vector_int.get_allocator().construct(&arr[i],i);

        for (int i = 0; i<7; i++) std::cout << ' ' << arr[i];
        std::cout << std::endl;

        for (int i = 0; i < 7; i++) 
            vector_int.get_allocator().destroy(&arr[i]);
        vector_int.get_allocator().deallocate(arr,7);
    }
}