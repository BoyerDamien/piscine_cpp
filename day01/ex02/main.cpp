/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:10:14 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/25 11:49:02 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ZombieEvent.hpp"

int main(int argc, char *argv[]) {
  ZombieEvent event = ZombieEvent();
  event.randomString(5);
  return 0;
}
