/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:28:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/02 17:45:01 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void stk_test4()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 6 < non-member functions > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
        	std::cout << "\033[34m" << "ft::vector<int> foo1 (2,200)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "ft::vector<int> bar1 (2,200)" << "\033[0m" << std::endl << std::endl;
            ft::vector<int> foo1 (2,200); 
            ft::vector<int> bar1 (2,200);
        	std::cout << "\033[34m" << "std::stack<int,ft::vector<int> > s1 (foo1)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,ft::vector<int> > s2 (bar1)" << "\033[0m" << std::endl << std::endl;
            std::stack<int,ft::vector<int> > s1 (foo1);  
            std::stack<int,ft::vector<int> > s2 (bar1);
            
			std::cout << "\033[34m" << "[ s1 == s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 == s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s1 != s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 != s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s1 < s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 < s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s1 > s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 > s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s1 <= s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 <= s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s1 >= s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 >= s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;


        	std::cout << "\033[34m" << "ft::vector<int> foo2 (2,200)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "ft::vector<int> bar2 (5,100)" << "\033[0m" << std::endl << std::endl;
            std::vector<int> foo2 (2,200); 
            std::vector<int> bar2 (5,100);
        	std::cout << "\033[34m" << "std::stack<int,std::vector<int> > s1 (foo2)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,std::vector<int> > s2 (bar2)" << "\033[0m" << std::endl << std::endl;
            std::stack<int,std::vector<int> > s3 (foo2);  
            std::stack<int,std::vector<int> > s4 (bar2);
            
			std::cout << "\033[34m" << "[ s3 == s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 == s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s3 != s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 != s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s3 < s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 < s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s3 > s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 > s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s3 <= s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 <= s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[34m" << "[ s3 >= s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 >= s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;  
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
		std::cout << "\033[33m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
        	std::cout << "\033[33m" << "ft::vector<int> foo1 (2,200)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "ft::vector<int> bar1 (2,200)" << "\033[0m" << std::endl << std::endl;
            ft::vector<int> foo1 (2,200); 
            ft::vector<int> bar1 (2,200);
        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s1 (foo1)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s2 (bar1)" << "\033[0m" << std::endl << std::endl;
            ft::stack<int,ft::vector<int> > s1 (foo1);  
            ft::stack<int,ft::vector<int> > s2 (bar1);
            
			std::cout << "\033[33m" << "[ s1 == s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 == s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s1 != s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 != s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s1 < s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 < s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s1 > s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 > s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s1 <= s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 <= s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s1 >= s2]" << '\t' << "==>" << "\033[0m" << '\t';
            (s1 >= s2) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;


        	std::cout << "\033[33m" << "ft::vector<int> foo2 (2,200)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "ft::vector<int> bar2 (5,100)" << "\033[0m" << std::endl << std::endl;
            std::vector<int> foo2 (2,200); 
            std::vector<int> bar2 (5,100);
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s1 (foo2)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s2 (bar2)" << "\033[0m" << std::endl << std::endl;
            ft::stack<int,std::vector<int> > s3 (foo2);  
            ft::stack<int,std::vector<int> > s4 (bar2);
            
			std::cout << "\033[33m" << "[ s3 == s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 == s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s3 != s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 != s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s3 < s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 < s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s3 > s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 > s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s3 <= s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 <= s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl;
			std::cout << "\033[33m" << "[ s3 >= s4]" << '\t' << "==>" << "\033[0m" << '\t';
            (s3 >= s4) ? std::cout << "YES" << std::endl :  std::cout << "NO" << std::endl; 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
	}
}