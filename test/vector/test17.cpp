/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test17.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:33:45 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:19 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "../../test.hpp"
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

void v_test17()
{
    ft::vector<int>::iterator it_vi;
    ft::vector<int> vector_int;
	srand(time(NULL));
	for (int i = 0; i < COUNT; i++)
		vector_int.push_back(rand() % COUNT);
    {
        ft::vector<int> vector_tmp_int(vector_int.begin(), vector_int.end());

        if (vector_int.size() != vector_tmp_int.size())
            std::cerr << "error: vector construction with ranges failed!!\n";
        for (int i = 0; i < COUNT; i++)
        {
            if (vector_int[i] != vector_tmp_int[i])
                std::cerr << "error: vector construction with ranges failed!!\n";
            vector_tmp_int.pop_back();
        }
        if (!vector_tmp_int.empty())
            std::cerr << "error: this vector should be empty!!\n";
    }
    {
        ft::vector<int> vector_tmp_int;

        vector_tmp_int = vector_int;
        if (vector_int.size() != vector_tmp_int.size())
            std::cerr << "error: vector assign failed!!\n";
        for (int i = 0; i < COUNT; i++)
        {
            if (vector_int[i] != vector_tmp_int[i])
                std::cerr << "error: vector assign failed!!\n";
        }
        vector_tmp_int.resize(0, 0);
        if (!vector_tmp_int.empty())
            std::cerr << "error: this vector should be empty!!\n";
    }
	
    {
			ft::vector<int> vector_tmp_int;
			int *arr;

			arr = vector_int.data();
			vector_tmp_int.resize(vector_int.size());

			it_vi = vector_tmp_int.begin();
			ft::swap(vector_int, vector_tmp_int);
			ft::vector<int>::iterator it_vic2 = vector_int.end();
			ft::vector<int>::const_iterator it_vic = vector_int.end();
			if (it_vic == it_vic2){}
			if (it_vi == it_vic2){}
			if (it_vic == it_vi){}
			if (it_vi == it_vic){}

		
			for (; it_vi != it_vic; ++it_vi, ++arr)
				*it_vi = *arr;

			vector_tmp_int.erase(vector_tmp_int.begin() + (COUNT / 2), vector_tmp_int.end());
			vector_tmp_int.insert(vector_tmp_int.end(), vector_int.begin() + (COUNT / 2), vector_int.end());
			for (int i = 0; i < COUNT; i++)
			{
				if (vector_int[i] != vector_tmp_int[i])
					std::cerr << "error: vector erase/insert failed!!\n";
			}
    }

    {
        ft::vector<int> vector_tmp_int(vector_int.begin(), vector_int.end());

        int var_count = COUNT;

        for (int i = 0; i < var_count; i++)
        {
            if (vector_tmp_int.at(i) > COUNT - 100)
            {
                vector_tmp_int.erase(vector_tmp_int.begin() + i);
                --var_count;
            }
        }
        std::cout << "VECTOR CONTENT : " << std::endl;
        std::cout << "*****************" << std::endl;
        for (it_vi = vector_tmp_int.begin(); it_vi != vector_tmp_int.end(); ++it_vi)
            std::cout << *it_vi << ' ';

        std::cout << std::endl;
        std::cout << "VECTOR SIZE : " << std::endl;
        std::cout << "*****************" << std::endl;
        std::cout << vector_tmp_int.size() << std::endl;
    }
    ft::vector<Buffer> vector_buffer;
    for (int i = 0; i < COUNT; i++)
        vector_buffer.push_back(Buffer(rand() % COUNT));
    {
        ft::vector<Buffer> vectro_tmp_buf(vector_buffer.begin(), vector_buffer.end());

        if (vector_buffer.size() != vectro_tmp_buf.size())
            std::cerr << "error: vector construction with ranges failed!!\n";
        for (int i = 0; i < COUNT; i++)
        {
            if (vector_buffer[i] != vectro_tmp_buf[i])
                std::cerr << "error: vector construction with ranges failed!!\n";
        }
        vectro_tmp_buf.clear();
        if (!vectro_tmp_buf.empty())
            std::cerr << "error: this vector should be empty!!\n";
    }
    {
        ft::vector<int> vector_tmp_int;

        vector_tmp_int = vector_int;

        ft::swap(vector_int, vector_tmp_int);
        if (vector_tmp_int == vector_int)
            std::cout << "comp eq\n";
        vector_tmp_int.pop_back();
        if (vector_tmp_int < vector_int)
            std::cout << "comp smaller\n";
        vector_int.pop_back();
        vector_int.pop_back();
        if (vector_tmp_int > vector_int)
            std::cout << "comp greater\n";
    }
    {
        try
        {
            vector_int.at(COUNT);
        }
        catch(...)
        {
            std::cout << "vector error at" << '\n';
        }
        
    }
    std::cout << "abc struct max size:" << ft::vector<Buffer>().max_size() << std::endl;
    std::cout << "Float max size:" << ft::vector<float>().max_size() << std::endl;
    std::cout << "Long max size:" << ft::vector<long>().max_size() << std::endl;
    std::cout << "Int max size:" << ft::vector<int>().max_size() << std::endl;
    std::cout << "Short max size:" << ft::vector<short>().max_size() << std::endl;
    std::cout << "Char max size:" << ft::vector<char>().max_size() << std::endl;
    {
        int *arr;

        arr = vector_int.get_allocator().allocate(7);

        for (int i = 0; i < 7; i++) 
            vector_int.get_allocator().construct(&arr[i],i);

        for (int i = 0; i<7; i++) std::cout << ' ' << arr[i];
        std::cout << std::endl;

        for (int i = 0; i < 7; i++) 
            vector_int.get_allocator().destroy(&arr[i]);
        vector_int.get_allocator().deallocate(arr,7);
    }
}