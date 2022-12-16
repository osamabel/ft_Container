/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:28:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/02 17:09:23 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void stk_test2()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 2 < size > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
			std::cout << "\033[34m" << "ft::vector<int> v1" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::vector<int> v2" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "ft::vector<int> v3 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::vector<int> v4 (3, 100)" << "\033[0m" << std::endl << std::endl;

			ft::vector<int> v1 ;          
            std::vector<int> v2 (10);
            ft::vector<int> v3 (3, 100);          
            std::vector<int> v4 (5, 100);        

            std::stack<int,ft::vector<int> > s1 (v1);  
            std::stack<int,std::vector<int> > s2 (v2);
            std::stack<int,ft::vector<int> > s3 (v3);  
            std::stack<int,std::vector<int> > s4 (v4);

        	std::cout << "\033[34m" << "std::stack<int,ft::vector<int> > s1 (v1)" << "\033[0m" << '\t' << "s1 size = " << s1.size() << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' <<"s2 size = " << s2.size() << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,ft::vector<int> > s3 (v3)" << "\033[0m" << '\t' << "s3 size = " << s3.size() << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,std::vector<int> > s4 (v4)" << "\033[0m" << '\t' <<"s4 size = " << s4.size() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\033[33m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
			std::cout << "\033[33m" << "ft::vector<int> v1" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "std::vector<int> v2" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "ft::vector<int> v3 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "std::vector<int> v4 (3, 100)" << "\033[0m" << std::endl << std::endl;

			ft::vector<int> v1 ;          
            std::vector<int> v2 (10);
            ft::vector<int> v3 (3, 100);          
            std::vector<int> v4 (5, 100);        

            ft::stack<int,ft::vector<int> > s1 (v1);  
            ft::stack<int,std::vector<int> > s2 (v2);
            ft::stack<int,ft::vector<int> > s3 (v3);  
            ft::stack<int,std::vector<int> > s4 (v4);

        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s1 (v1) " << "\033[0m" << '\t' << "s1 size = " << s1.size() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' <<"s2 size = " << s2.size() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s3 (v3) " << "\033[0m" << '\t' << "s3 size = " << s3.size() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s4 (v4)" << "\033[0m" << '\t' <<"s4 size = " << s4.size() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}