/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 09:16:09 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 10:00:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Human.hpp"
#include <iostream>

int main(int arg, char *argv[]) {
  Human bob;

  std::cout << bob.identify() << std::endl;
  std::cout << bob.getBrain().identify() << std::endl;
  return 0;
}
