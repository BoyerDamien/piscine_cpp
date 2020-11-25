/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:26:11 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/25 12:26:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANNUAIRE_CLASSS_H
#define ANNUAIRE_CLASSS_H
#include "./Contact.class.hpp"
#include <iostream>

class Annuaire {

private:
  Contact _contacts[8];
  int _contact_index;

  bool _checkCommand(std::string);
  void _showContacts(void) const;
  std::string _readInput(const char *) const;
  bool _checkInput(const char *, const char *) const;

public:
  int run(void);
  void addContact(void);
  void searchContact(void) const;
  void showAttribute(Contact, std::string) const;
};

#endif
