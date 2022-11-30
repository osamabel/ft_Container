/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

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