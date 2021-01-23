/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:56:47 by dboyer              #+#    #+# */
/*   Updated: 2021/01/23 15:26:10 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <iostream>

static std::string ft_str_trim(std::string str, char c)
{
	size_t first = str.find_first_not_of(c);
	size_t last = str.find_last_not_of(c);
	if (first != std::string::npos && last != std::string::npos)
		return str.substr(first, (last - first + 1));
	return "";
}

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::cout << Scalar(ft_str_trim(argv[1], ' ')) << std::endl;
		return 0;
	}
	if (argc > 2)
	{
		std::cerr << "Too much arguments" << std::endl;
		return 1;
	}
	std::cerr << "Not enought arguments" << std::endl;
	return 1;
}
