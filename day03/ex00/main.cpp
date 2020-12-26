/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:43:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/26 10:22:45 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

void test(FragTrap object, std::string target, int dammage) {

  object.meleeAttack(target);
  object.rangedAttack(target);
  object.vaulthunter_dot_exe(target);
  object.takeDamage(dammage);
  object.meleeAttack(target);
}

int main(void) {
  std::string target = "téo";

  // Test with default constructor
  FragTrap defaultConst = FragTrap();
  test(defaultConst, target, 10);

  // Test with simple constructor
  FragTrap simpleConst = FragTrap("Damien");
  test(simpleConst, target, 10);

  // Test with copy copy constructor
  FragTrap copyConst = FragTrap(simpleConst);
  test(copyConst, target, 10);

  return 0;
}
