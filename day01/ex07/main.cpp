/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:33:39 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 11:37:26 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>

bool readLines(const char *path, std::string &result)
{

	std::string line;
	std::ifstream file(path);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			result += line;
			result += "\n";
		}
		file.close();
		return true;
	}
	std::cerr << "Error: " << path << " does not exist" << std::endl;
	return false;
}

bool writeLines(const char *path, const char *str)
{
	std::ofstream file(path);
	if (file.is_open())
	{
		file << str;
		file.close();
		return true;
	}
	std::cerr << "Error: " << path << " does not exist" << std::endl;
	return false;
}

void replaceAll(std::string &text, std::string to_search,
				const char *to_replace)
{
	size_t pos;

	while ((pos = text.find(to_search)) != std::string::npos)
	{
		text.replace(pos, to_search.length(), to_replace);
	}
}

int main(int argc, char *argv[])
{

	std::string text;
	if (argc == 4 && readLines(argv[1], text))
	{
		replaceAll(text, argv[2], argv[3]);
		writeLines(argv[1], text.c_str());
		return 0;
	}
	else if (argc != 4)
	{
		std::cerr << "Error: the number of arguments is wrong !" << std::endl;
	}
	return 1;
}
