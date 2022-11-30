/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test13.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void v_test13()
{
std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 13 < erase > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v;
            std::vector<int>::iterator it;
			std::cout << "\033[34m" << "std::vector<int> v : " << "\033[0m" << std::endl;

            for (int i=1; i<=10; i++)
                v.push_back(i);
			std::cout << "\033[34m" << "fill v [1 - 10]" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
            
            it = v.erase (v.begin() + 5);
			std::cout << "\033[34m" << "v.erase (v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

            it = v.erase (v.begin(),v.begin() + 2);
			std::cout << "\033[34m" << "v.erase(v.begin(),v.begin() + 2) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
                
            it = v.erase (v.begin() + 2,v.begin() + 5);
			std::cout << "\033[34m" << "v.erase (v.begin() + 2,v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v =>" << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[32m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            ft::vector<int> v;
            ft::vector<int>::iterator it;
			std::cout << "\033[32m" << "ft::vector<int> v : " << "\033[0m" << std::endl;

            for (int i=1; i<=10; i++)
                v.push_back(i);
			std::cout << "\033[32m" << "fill v [1 - 10]" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
            
            it = v.erase (v.begin() + 5);
			std::cout << "\033[32m" << "v.erase (v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

            it = v.erase (v.begin(),v.begin() + 2);
			std::cout << "\033[32m" << "v.erase(v.begin(),v.begin() + 2) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
                
            it = v.erase (v.begin() + 2,v.begin() + 5);
			std::cout << "\033[32m" << "v.erase (v.begin() + 2,v.begin() + 5) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v =>" << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}