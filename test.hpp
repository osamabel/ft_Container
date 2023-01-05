/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:29:44 by obelkhad          #+#    #+#             */
/*   Updated: 2023/01/01 13:23:34 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_H
#define TEST_H

#include "Containers/ft_vector.hpp"
#include <vector>
#include "Containers/ft_stack.hpp"
#include <stack>
#include "Containers/ft_map.hpp"
#include <map>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#define COUNT 500000

struct Buffer
{
    long id;
    int ibuff[42];
    char cbuff[1337];
    Buffer(int id) : id(id) {}
    bool operator!=(Buffer rhs)
    {
        return (id != rhs.id);
    }
};


void v_test0();
void v_test1();
void v_test2();
void v_test3();
void v_test4();
void v_test5();
void v_test6();
void v_test7();
void v_test8();
void v_test9();
void v_test10();
void v_test11();
void v_test12();
void v_test13();
void v_test14();
void v_test15();
void v_test16();
void v_test17();

void stk_test0();
void stk_test1();
void stk_test2();
void stk_test3();
void stk_test4();

void map_test0();

void set_test0();

#endif