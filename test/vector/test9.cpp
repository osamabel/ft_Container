/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test9.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void v_test9()
{
	 std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 9 < assign > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v(10);
        	std::cout << "\033[34m" << "std::vector<int> v(10)" << "\033[0m" << std::endl;

        	std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            
            v.assign(15, 10);
        	std::cout << "\033[34m" << "v.assign(15, 10) : " << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
          
            std::vector<int> v2;
        	std::cout << "\033[34m" << "std::vector<int> v2" << "\033[0m" << std::endl;
            v2.push_back(5);
        	std::cout << "\033[34m" << "v2.push_back(5)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;
        	std::cout << "\033[34m" << "v2.assign(v.begin() + 1, v.end() - 1)" << "\033[0m" << std::endl;
            v2.assign(v.begin() + 1, v.end() - 1);
        	std::cout << "\033[34m" << "v2 =>" << "\033[0m";
            for (std::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            // ft::vector<int> v(10);
            ft::vector<int> v(10);
        	std::cout << "\033[32m" << "ft::vector<int> v(10)" << "\033[0m" << std::endl;

        	std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
            
			//v.assign(15, 10)
            v.assign(15, 10);
        	std::cout << "\033[32m" << "v.assign(15, 10) : " << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | " << "capacity = " << v.capacity() << std::endl << std::endl;
          
            // ft::vector<int> v2;
            ft::vector<int> v2;
        	std::cout << "\033[32m" << "ft::vector<int> v2" << "\033[0m" << std::endl;
            v2.push_back(5);
        	std::cout << "\033[32m" << "v2.push_back(5)" << "\033[0m" << std::endl;
        	std::cout << "\033[32m" << "v2 =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;
        	std::cout << "\033[32m" << "v2.assign(v.begin() + 1, v.end() - 1)" << "\033[0m" << std::endl;
			
			//v2.assign(v.begin() + 1, v.end() - 1)
            v2.assign(v.begin() + 1, v.end() - 1);
        	std::cout << "\033[32m" << "v2 =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v2.begin(); i < v2.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size 2 = " << v2.size() << " | " << "capacity 2 = " << v2.capacity() << std::endl << std::endl;		
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }  
    }
}