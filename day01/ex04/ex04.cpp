/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:10:42 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 09:13:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[]) {
  std::string mystring = "HI THIS IS BRAIN";
  std::string *myStringPtr = &mystring;
  std::string &mystringRef = mystring;

  std::cout << "Pointer = " << *myStringPtr << std::endl;
  std::cout << "Ref = " << mystringRef << std::endl;
  return 0;
}
