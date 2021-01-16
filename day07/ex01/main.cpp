/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:04:01 by root              #+#    #+#             */
/*   Updated: 2021/01/16 15:13:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

void myFun(int i)
{
	std::cout << i << std::endl;
}

void myFun(std::string i)
{
	std::cout << i << std::endl;
}

int main(void)
{
	int arr[] = {1, 2, 3};
	std::string stringArr[] = {"test1", "test2", "test3"};

	::iter<int>(arr, 3, &myFun);
	::iter<std::string>(stringArr, 3, &myFun);

	return 0;
}
