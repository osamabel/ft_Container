/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test15.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void v_test15()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 15 < clear > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;
            v.push_back (100);
            v.push_back (200);
            v.push_back (300);
			std::cout << "\033[34m" << "std::vector<int> v => [ 100 , 200 , 300 ]" << "\033[0m" << std::endl;

			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;

            v.clear();
			std::cout << "\033[34m" << "v.clear() : " << "\033[0m" << std::endl;
            std::cout << std::endl;
			std::cout << "\033[34m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[34m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;

            v.push_back (1101);
            v.push_back (2202);
			
			std::cout << "\033[34m" << "push (1101), (2202)" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
			
			std::cout << "\033[34m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[34m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;
            v.push_back (100);
            v.push_back (200);
            v.push_back (300);
			std::cout << "\033[32m" << "ft::vector<int> v => [ 100 , 200 , 300 ]" << "\033[0m" << std::endl;

			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
            v.clear();
			std::cout << "\033[32m" << "v.clear() : " << "\033[0m" << std::endl;
            std::cout << std::endl;
			std::cout << "\033[32m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[32m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;

            v.push_back (1101);
            v.push_back (2202);
			
			std::cout << "\033[32m" << "push (1101), (2202)" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << std::endl;
			
			std::cout << "\033[32m" << ")==> size : " << v.size() << "\033[0m" << std::endl;
			std::cout << "\033[32m" << ")==> capacity : " << v.capacity() << "\033[0m" << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

}