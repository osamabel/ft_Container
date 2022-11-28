/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test14.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/27 21:40:51 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void test14()
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