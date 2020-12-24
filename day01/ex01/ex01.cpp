/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:01:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/24 11:09:16 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void memoryLeak() {
  std::string *panthere = new std::string("String panthere");
  std::cout << *panthere << std::endl;
  delete panthere;
}
