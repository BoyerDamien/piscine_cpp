/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>                +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:27:53 by dboyer              #+#    #+# */
/*   Updated: 2021/01/23 15:35:07 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

const std::string ALNUM =
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

void *serialize(void)
{
	Data *data = new Data;
	std::srand(std::time(NULL));

	for (int i = 0; i < 8; i++)
	{
		data->s1.push_back(ALNUM[rand() % ALNUM.length()]);
		data->s2.push_back(ALNUM[rand() % ALNUM.length()]);
	}
	data->n = rand() % 10;
	std::cout << "s1: " << data->s1 << "\nn: " << data->n
			  << "\ns2: " << data->s2 << std::endl
			  << std::endl;
	return reinterpret_cast<void *>(data);
}

Data *deserialize(void *raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	void *data = serialize();
	Data *deserialized = deserialize(data);
	std::cout << "s1: " << deserialized->s1 << "\nn: " << deserialized->n
			  << "\ns2: " << deserialized->s2 << std::endl;
	delete deserialized;

	return 0;
}
