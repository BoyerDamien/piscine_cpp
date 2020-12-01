/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:29:06 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/28 11:12:50 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/c++config.h>
#include <cctype>
#include <iostream>
#include <string>

std::string ft_toupper(std::string str) {
  std::string ret;
  for (auto c : str) {
    ret.push_back(std::toupper(c));
  }
  return ret;
}

std::string ft_str_trim(std::string str, char c) {
  size_t first = str.find_first_not_of(c);
  size_t last = str.find_last_not_of(c);
  if (first != std::string::npos && last != std::string::npos)
    return str.substr(first, (last - first + 1));
  return "";
}

int main(int argc, char *argv[]) {
  std::string output;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (int i = 1; i < argc; i++) {
      output += ft_str_trim(ft_toupper(argv[i]), ' ') + " ";
    }
    std::cout << ft_str_trim(output, ' ') << std::endl;
  }
}
