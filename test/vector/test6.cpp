/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/27 21:36:55 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void test6()
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