/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/27 21:37:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void test7()
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