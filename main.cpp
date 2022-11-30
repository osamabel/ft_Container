/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:55:39 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:55:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Containers/ft_vector.hpp"
#include "test.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <type_traits>


int main ()
{	
	int test;
	std::cout << "STD is_ integral<int> : " << std::is_integral<int>::value;
	void (*vectorTest[18])() = {v_test0, v_test1, v_test2, v_test3, v_test4, v_test5, v_test6, v_test7, v_test8, v_test9, v_test10, v_test11, v_test12, v_test13, v_test14, v_test15, v_test16, v_test17};
	while (1)
	{
		std::cout << "there are 1 to 17 tests vector, please choose One at time." << std::endl;
		std::cout << "\033[36m" << "[ *** ] please compaire { STD OUTPUT} & { FT OUTPUT }, should be the same !!!" << "\033[0m" << std::endl;
		std::cout << "test number : "; 
		std::cin >> test;
		if (test >= 0 && test <= 17)
		{
			system("clear");
			vectorTest[test]();
		}
		else
			std::cout << "\033[31m"  << "error : range form [1 - 16]" << "\033[0m" << std::endl;
	}
    
    return (0);
}


