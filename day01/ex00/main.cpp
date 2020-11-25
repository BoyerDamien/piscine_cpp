/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:41:54 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/24 17:58:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Pony.hpp"

void ponyOnTheStack(std::string name) {
  Pony pony = Pony(name);
  pony.announce();
}

void ponyOnTheHeap(std::string name) {
  Pony *pony = new Pony(name);
  pony->announce();
  delete pony;
}

int main(int argc, char *argv[]) {
  ponyOnTheHeap("on the heap");
  ponyOnTheStack("on the stack");
  return 0;
}
