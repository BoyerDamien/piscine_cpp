/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:02:43 by root              #+#    #+#             */
/*   Updated: 2021/01/16 17:04:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Array.hpp"
#include <iostream>

int main(void)
{
	My::Array<int> test(3);

	test[0] = 1;
	test[1] = 2;
	test[2] = 3;

	try
	{
		test[3] = 4;
	}
	catch (My::MemoryAccessException const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	My::Array<float> testF;
	try
	{
		testF[0] = 3.2;
	}
	catch (My::MemoryAccessException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << test << std::endl;
	std::cout << testF << std::endl;

	return 0;
}
