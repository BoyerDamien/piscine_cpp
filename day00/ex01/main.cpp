/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:26:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/25 12:26:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Annuaire.class.hpp"
#include "./Contact.class.hpp"
#include <string>

int main(int argc, char **argv) {
  Annuaire app = Annuaire();
  return (app.run());
  return (0);
}
