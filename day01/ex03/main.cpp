/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:10:14 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/26 09:07:59 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieHorde.hpp"
int main(int argc, char *argv[]) {
  ZombieHorde horde = ZombieHorde(10);
  horde.announce();
  return 0;
}
