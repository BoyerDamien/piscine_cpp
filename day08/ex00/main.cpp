/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 08:48:06 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/17 08:59:30 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfind.hpp"
#include <set>
#include <vector>

int main(void)
{
	std::vector<int> test1;
	for (int i = 0; i < 10; i++)
	{
		test1.push_back(i);
	}
	std::cout << easyfind(test1, 4) << std::endl;

	std::set<int> test2;
	for (int i = 0; i < 10; i++)
	{
		test2.insert(i);
	}

	try
	{
		easyfind(test2, 14);
	}
	catch (NotFoundException const &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
