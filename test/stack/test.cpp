/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:28:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/12/26 09:51:20 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../test.hpp"

void stk_test0()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 0 ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
	{
		ft::stack<int, ft::vector<int> > s;
		s.push(5);
		assert(s.top() == 5);
		s.push(6);
		assert(s.top() == 6);
		s.pop();
		assert(s.top() == 5);
    	std::cout << "testing stack with my vector + top | push | pop\n";
  	}
	{
		ft::stack<int> ss;
		assert(ss.empty());
		ss.push(5);
		assert(!ss.empty());
		ss.pop();
		assert(ss.empty());
		std::cout << "testing stack with my vector + empty\n";
	}
	{
		ft::stack<double, std::vector<double> > s;
		s.push(5);
		assert(s.top() == 5);
		s.push(6);
		assert(s.top() == 6);
		s.pop();
		assert(s.top() == 5);
		std::cout << "testing stack with stl vector + top | push | pop\n";
	}
	{
		ft::stack<int, std::vector<int> > ss;
		assert(ss.empty());
		ss.push(5);
		assert(!ss.empty());
		ss.pop();
		assert(ss.empty());
		std::cout << "testing stack with stl vector + empty\n";
	}
	{
		ft::stack<double, std::list<double> > s;
		s.push(5);
		assert(s.top() == 5);
		s.push(6);
		assert(s.top() == 6);
		s.pop();
		assert(s.top() == 5);
		std::cout << "testing stack with stl list + top | push | pop\n";
	}
	{
		ft::stack<int, std::list<int> > ss;
		assert(ss.empty());
		ss.push(5);
		assert(!ss.empty());
		ss.pop();
		assert(ss.empty());
		std::cout << "testing stack with stl list + empty\n";
	}
}

void stk_test1()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 1 < empty > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
        	std::cout << "\033[34m" << "ft::vector<int> v1" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::vector<int> v2" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "ft::vector<int> v3 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::vector<int> v4 (3, 100)" << "\033[0m" << std::endl << std::endl;

            ft::vector<int> v1 ;          
            std::vector<int> v2;
            ft::vector<int> v3 (3, 100);          
            std::vector<int> v4 (3, 100);        

            std::stack<int,ft::vector<int> > s1 (v1);  
            std::stack<int,std::vector<int> > s2 (v2);
            std::stack<int,ft::vector<int> > s3 (v3);  
            std::stack<int,std::vector<int> > s4 (v4);

            std::cout << std::boolalpha;
        	std::cout << "\033[34m" << "std::stack<int,ft::vector<int> > s1 (v1)" << "\033[0m" << '\t' << "s1 is empty ? " << s1.empty() << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' << "s2 is empty ? " << s2.empty() << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,ft::vector<int> > s3 (v3)" << "\033[0m" << '\t' << "s3 is empty ? " << s3.empty() << std::endl;
        	std::cout << "\033[34m" << "std::stack<int,std::vector<int> > s4 (v4)" << "\033[0m" << '\t' << "s4 is empty ? " << s4.empty() << std::endl << std::endl;
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
            std::vector<int> v2;
            ft::vector<int> v3 (3, 100);          
            std::vector<int> v4 (3, 100);        

            ft::stack<int,ft::vector<int> > s1 (v1);  
            ft::stack<int,std::vector<int> > s2 (v2);
            ft::stack<int,ft::vector<int> > s3 (v3);  
            ft::stack<int,std::vector<int> > s4 (v4);

            std::cout << std::boolalpha;
        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s1 (v1) " << "\033[0m" << '\t' << "s1 is empty ? " << s1.empty() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' << "s2 is empty ? " << s2.empty() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s3 (v3) " << "\033[0m" << '\t' << "s3 is empty ? " << s3.empty() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s4 (v4)" << "\033[0m" << '\t' << "s4 is empty ? " << s4.empty() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
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
void stk_test3()
{
	std::cout << std::endl << "\033[36m" << "-----------------------------------[ test 3 < push pop top > ]-------------------------------------- " << "\033[0m" << std::endl << std::endl;
    {
        std::cout << "\033[34m" << "----------------------- STD -----------------------" << "\033[0m" << std::endl;
        try
        {
        	std::cout << "\033[34m" << "ft::vector<int> v1 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[34m" << "std::vector<int> v2 (3, 100)" << "\033[0m" << std::endl << std::endl;
            
            ft::vector<int> v1 (3, 300);          
            std::vector<int> v2 (3, 200);        

            std::stack<int,ft::vector<int> > s1 (v1);  
            std::stack<int,std::vector<int> > s2 (v2);

        	std::cout << "\033[34m" << "ft::stack<int,ft::vector<int> > s1 (v1) " << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
        	std::cout << "\033[34m" << "ft::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(15);
			s2.push(15);
			std::cout << "\033[34m" << "s1.push(15)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[34m" << "s2.push(15)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(600);
			s2.push(600);
			std::cout << "\033[34m" << "s1.push(600)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[34m" << "s2.push(600)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.pop();
			s2.pop();
			std::cout << "\033[34m" << "s1.pop()" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[34m" << "s2.pop()" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;

        }
        catch(const std::string str)
        {
            std::cerr << str << '\n';
        }
        std::cout << "\033[33m" << "----------------------- FT -----------------------" << "\033[0m" << std::endl;
        try
        {
            std::cout << "\033[33m" << "ft::vector<int> v1 (3, 100)" << "\033[0m" << std::endl;
        	std::cout << "\033[33m" << "std::vector<int> v2 (3, 100)" << "\033[0m" << std::endl << std::endl;
            
            ft::vector<int> v1 (3, 300);          
            std::vector<int> v2 (3, 200);        

            ft::stack<int,ft::vector<int> > s1 (v1);  
            ft::stack<int,std::vector<int> > s2 (v2);

        	std::cout << "\033[33m" << "ft::stack<int,ft::vector<int> > s1 (v1) " << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
        	std::cout << "\033[33m" << "ft::stack<int,std::vector<int> > s2 (v2)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(15);
			s2.push(15);
			std::cout << "\033[33m" << "s1.push(15)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[33m" << "s2.push(15)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.push(600);
			s2.push(600);
			std::cout << "\033[33m" << "s1.push(600)" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[33m" << "s2.push(600)" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
			
			s1.pop();
			s2.pop();
			std::cout << "\033[33m" << "s1.pop()" << "\033[0m" << '\t' << "s1 top = " << s1.top() << std::endl;
			std::cout << "\033[33m" << "s2.pop()" << "\033[0m" << '\t' << "s2 top = " << s2.top() << std::endl << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

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