/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:29:06 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/03 11:29:30 by dess             ###   ########.fr       */
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

int main(int argc, char *argv[]) {
  std::string output;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    for (int i = 1; i < argc; i++) {
      output += ft_toupper(argv[i]);
    }
    std::cout << output << std::endl;
  }
}
