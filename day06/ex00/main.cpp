/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:56:47 by dboyer              #+#    #+#             */
/*   Updated: 2021/01/16 09:15:17 by dboyer             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		std::cout << Scalar(argv[1]) << std::endl;
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
