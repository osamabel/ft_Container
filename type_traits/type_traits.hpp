/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:22:18 by obelkhad          #+#    #+#             */
/*   Updated: 2022/11/24 20:38:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRIATS
#define TYPE_TRIATS

namespace ft
{
	/*------------------------------------------------------------------------*/
	/*                             [ enable_if ]                              */
	/*------------------------------------------------------------------------*/
	template<bool B, class T = void>
	struct enable_if
	{};
	
	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	/*------------------------------------------------------------------------*/
	
	/*------------------------------------------------------------------------*/
	/*                             [ remove_volatile ]
	/*
	/*	remove_const : removes the topmost [ volatile ]                       */
	/*------------------------------------------------------------------------*/

	template <class _Tp> 
	struct remove_const
	{
		typedef _Tp type;
	};
	template <class _Tp>
	struct remove_const<const _Tp> 
	{
		typedef _Tp type;
	};
	/*------------------------------------------------------------------------*/
	
	/*------------------------------------------------------------------------*/
	/*                             [ remove_const ]
	/*
	/*	remove_const : removes the topmost [ const ]                          */
	/*------------------------------------------------------------------------*/
	template <class _Tp>
	struct remove_volatile
	{
		typedef _Tp type;
	};
	template <class _Tp>
	struct remove_volatile<volatile _Tp>
	{
		typedef _Tp type;
	};
	/*------------------------------------------------------------------------*/
	
	/*------------------------------------------------------------------------*/
	/*                             [ remove_cv ]	
	/*
	/*	remove_cv : removes the topmost [ Const ], or the topmost [ Volatile ],
	/*	or both, if present.   
	/*    
	/* Ex:
	/* std::remove_cv<const int>::type; <=> int
	/* std::remove_cv<volatile int>::type; <=> int
	/* std::remove_cv<const volatile int>::type; <=> int
	/* std::remove_cv<int* const volatile>::type <=> int*
	/*------------------------------------------------------------------------*/
	// Provides the member typedef type which is the same as T,
	// except that its topmost cv-qualifiers are removed.
	// [ Topmost cv-qualifiers ] <=> (const and volatile) type qualifiers 
	template <class _Tp> struct remove_cv
	{
		// [ type ] : the type _Tp without cv-qualifier
		typedef typename ft::remove_volatile<typename ft::remove_const<_Tp>::type>::type type;
	};
	/*------------------------------------------------------------------------*/


	/*------------------------------------------------------------------------*/
	/*                           [ integral_constant ]
	/*	
	/* provide compile-time constants as types
	/*------------------------------------------------------------------------*/
	template <bool __b>
	struct integral_constant
	{
		static const bool      value = __b;
	};
	/*------------------------------------------------------------------------*/
	
	/*------------------------------------------------------------------------*/
	/*                           [ is_integral ]                              */
	/*	
	/*	Provides the member constant value which is equal to true, 
	/*	if T is the type [ bool ], [ char ], [ char8_t ] (since C++20), 
	/*	[ char16_t ], [ char32_t ], [ wchar_t ], [ short ], [ int ],
	/*	[ long ], [ long long ]												  */
	/*------------------------------------------------------------------------*/
	template <class _Tp> struct __libcpp_is_integral                     : public ft::integral_constant<false> {};
	template <>          struct __libcpp_is_integral<bool>               : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<char>               : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<signed char>        : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<unsigned char>      : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<wchar_t>            : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<char16_t>           : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<char32_t>           : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<short>              : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<unsigned short>     : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<int>                : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<unsigned int>       : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<long>               : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<unsigned long>      : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<long long>          : public ft::integral_constant<true> {};
	template <>          struct __libcpp_is_integral<unsigned long long> : public ft::integral_constant<true> {};


	template <class _Tp>
	struct is_integral : public __libcpp_is_integral<typename ft::remove_cv<_Tp>::type> {};

	/*------------------------------------------------------------------------*/








}	//namespace ft
#endif


#include <iostream>
#include <type_traits>

	template <class T, T __v>
	struct integral_constant
	{
		static const T      				value = __v;
		typedef integral_constant<T,__v> 	type;
	};


template <unsigned n>
struct factorial : std::integral_constant<int, n * factorial<n-1>::value> {};

template <>
struct factorial<0> : std::integral_constant<int,1> {};

int main() {
  std::cout << factorial<5>::value;  // constexpr (no calculations on runtime)
  return 0;
}