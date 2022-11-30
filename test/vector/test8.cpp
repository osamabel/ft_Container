/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

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