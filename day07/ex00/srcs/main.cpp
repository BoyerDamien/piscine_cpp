/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:33:49 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 14:56:59 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>
#include <string>

const std::string SEPARATOR =
	"\n\n################################################"
	"##########################################\n\n";

void show_result(std::string message, bool status)
{

	std::cerr << SEPARATOR << std::endl;
	if (status)
	{
		std::cerr << message << ": [OK]" << std::endl;
	}
	else
	{
		std::cerr << message << ": [KO]" << std::endl;
	}
	std::cerr << SEPARATOR << std::endl;
}

bool test_swap(void)
{
	std::string v1 = "v1";
	std::string v2 = "v2";

	My::swap<std::string>(v1, v2);

	bool result = v1 == "v2" && v2 == "v1";

	int v3 = 100;
	int v4 = 200;
	My::swap<int>(v3, v4);

	return result && v3 == 200 && v4 == 100;
}

bool test_min(void)
{
	int v1 = 100;
	int v2 = 300;

	bool result = My::min<int>(v1, v2) == v1;

	float v3 = 100.23;
	float v4 = 200.34;

	return result && My::min<float>(v3, v4) == v3;
}

bool test_max(void)
{
	int v1 = 100;
	int v2 = 300;

	bool result = My::max<int>(v1, v2) == v2;

	float v3 = 100.23;
	float v4 = 200.34;

	return result && My::max<float>(v3, v4) == v4;
}

int main(void)
{
	// Test swap
	show_result("Test swap", test_swap());

	// Test min
	show_result("Test min", test_min());

	// Test max
	show_result("Test max", test_max());
	return 0;
}
