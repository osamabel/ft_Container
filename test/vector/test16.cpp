/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test16.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/28 18:04:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void test16()
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
			std::cout << "\033[34m" << ")=======> foo.swap(bar)"<< "\033[0m" << '\t';
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
			// std::cout << "\033[32m" << "[ foo != bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo != bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo < bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo < bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo > bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo > bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo <= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo <= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo >= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo >= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;

            // std::cout << std::endl;
            // foo.swap(bar);
			// std::cout << "\033[32m" << ")=======> foo.swap(bar)"<< "\033[0m" << '\t';
			// std::cout << "\033[32m" << "[ foo == bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo == bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo != bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo != bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo < bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo < bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo > bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo > bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo <= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo <= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			// std::cout << "\033[32m" << "[ foo >= bar ]" << '\t' << "==>" << "\033[0m" << '\t';
            // (foo >= bar) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }   
}