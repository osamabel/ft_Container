/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/27 21:35:25 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void test3()
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