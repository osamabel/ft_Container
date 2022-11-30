/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

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