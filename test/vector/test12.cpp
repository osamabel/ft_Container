/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test12.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:33:23 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void v_test12()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 12 < insert > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
		std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::vector<int> v (3,100);
            std::vector<int>::iterator it;

			std::cout << "\033[34m" << "std::vector<int> v (3,100) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
                    
            it = v.begin();
            it = v.insert ( it , 200 );
			std::cout << "\033[34m" << "it = v.insert ( v.begin() , 200 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            
            it = v.begin() + 2;
            v.insert ( it , 6 , 10 );
			std::cout << "\033[34m" << "it = v.insert ( v.begin() + 2, 6, 10 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v => " << "\033[0m";
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << "\t" << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl << std::endl;

			std::cout << "\033[34m" << "myarray [] = { 501,502,503 }" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v.insert (v.begin() + 1, myarray, myarray+3)" << "\033[0m" << std::endl;
            int myarray [] = { 501,502,503 };
			std::cout << "\033[34m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 1, myarray, myarray+3);
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

			std::cout << "\033[34m" << "With enough CAPACIRY !! " << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v.insert (v.begin() + 7, myarray, myarray+3)" << "\033[0m" << std::endl;
			std::cout << "\033[34m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 7, myarray, myarray+3);
            for (std::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
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
            ft::vector<int> v (3,100);
            ft::vector<int>::iterator it;

			std::cout << "\033[32m" << "ft::vector<int> v (3,100) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << std::endl << std::endl;
                    
            it = v.begin();
            it = v.insert ( it , 200 );
			std::cout << "\033[32m" << "it = v.insert ( v.begin() , 200 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            
            it = v.begin() + 2;
            v.insert ( it , 6 , 10 );
			std::cout << "\033[32m" << "it = v.insert ( v.begin() + 2, 6, 10 ) : " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v => " << "\033[0m";
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i ;
            std::cout << "\t" << "size = " << v.size() << " | capacity = " << v.capacity() << " | *it = " << *it << std::endl << std::endl;
            std::cout << "*(it - 2) = " << *(it - 2) << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl << std::endl;

			std::cout << "\033[32m" << "myarray [] = { 501,502,503 }" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v.insert (v.begin() + 1, myarray, myarray+3)" << "\033[0m" << std::endl;
            int myarray [] = { 501,502,503 };
			std::cout << "\033[32m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 1, myarray, myarray+3);
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
            std::cout << "*(it - 1) = " << *(it - 1) << std::endl;
            std::cout << "*it = " << *it << std::endl;
            std::cout << "*(it + 1) = " << *(it + 1) << std::endl;
            std::cout << "*(it + 2) = " << *(it + 2) << std::endl << std::endl;

			std::cout << "\033[32m" << "With enough CAPACIRY !! " << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v.insert (v.begin() + 7, myarray, myarray+3)" << "\033[0m" << std::endl;
			std::cout << "\033[32m" << "v1 => " << "\033[0m";
            it = v.insert (v.begin() + 7, myarray, myarray+3);
            for (ft::vector<int>::iterator i = v.begin(); i < v.end() ; i++)
                std::cout << "\t" << *i;
            std::cout << '\t' << "size = " << v.size() << " | capacity = " << v.capacity() <<  " | *it = " <<  *it << std::endl << std::endl;
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