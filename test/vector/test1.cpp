/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

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