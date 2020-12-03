/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:26:28 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/03 16:23:05 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Annuaire.class.hpp"
#include "./Contact.class.hpp"
#include <string>

int main(void) {
  Annuaire app = Annuaire();
  return (app.run());
  return (0);
}
