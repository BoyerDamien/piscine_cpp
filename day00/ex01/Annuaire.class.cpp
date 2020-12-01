/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Annuaire.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:26:01 by dboyer            #+#    #+#             */
/*   Updated: 2020/11/28 13:53:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Annuaire.class.hpp"
#include "Contact.class.hpp"
#include <cstddef>
#include <cstdio>
#include <iomanip>
#include <regex>
#include <string>

static std::string ft_str_trim(std::string str, char c) {
  size_t first = str.find_first_not_of(c);
  size_t last = str.find_last_not_of(c);
  if (first != std::string::npos && last != std::string::npos)
    return str.substr(first, (last - first + 1));
  return "";
}
std::string Annuaire::_readInput(const char *message) const {
  std::string line;
  std::cout << std::endl << message;
  std::getline(std::cin, line);
  return ft_str_trim(line, ' ');
}

void Annuaire::addContact(void) {
  if (this->_contact_index < 8 && this->_contact_index >= 0) {
    this->_contacts[this->_contact_index++].set_attributes();
  } else {
    this->_contacts[this->_contact_index - 1].set_attributes();
  }
}

void Annuaire::showAttribute(Contact contact, std::string attribute) const {
  std::string result = contact.get(attribute);
  std::cout << result << std::setw(11 - result.length()) << "|";
}

void Annuaire::_showContacts(void) const {
  const std::string attributes[] = {"index", "first_name", "last_name",
                                    "nickname"};
  for (std::string attribute : attributes) {
    for (int i = 0; i < this->_contact_index; i++) {
      if (attribute.compare("index") == 0) {
        this->showAttribute(this->_contacts[i], std::to_string(i));
      } else {
        this->showAttribute(this->_contacts[i], attribute);
      }
    }
    std::cout << std::endl;
  }
}

bool Annuaire::_checkInput(const char *input, const char *re) const {
  std::regex r(re);
  std::cmatch m;
  return (std::regex_match(input, m, r));
}

void Annuaire::searchContact(void) const {
  if (this->_contact_index > 0) {
    this->_showContacts();
    std::string input = this->_readInput("Index: ");
    if (this->_checkInput(input.c_str(), "[0-9]")) {
      int index = std::stoi(input);
      if (index < this->_contact_index) {
        this->_contacts[index].show();
      } else {
        std::cerr << "Erreur: index invalide" << std::endl;
        this->searchContact();
      }
    } else {
      std::cerr << "Erreur: l'entrée doit être numérique" << std::endl;
      this->searchContact();
    }
  } else {
    std::cerr << "Erreur: vous n'avez pas encore ajouter de contacte. Utiliser "
                 "la commande ADD pour cela."
              << std::endl;
  }
}

bool Annuaire::_checkCommand(std::string cmd) {
  if (cmd.compare("EXIT") == 0) {
    std::cout << "Merci! Au revoir!" << std::endl;
    return (false);
  } else if (cmd.compare("ADD") == 0) {
    this->addContact();
  } else if (cmd.compare("SEARCH") == 0) {
    this->searchContact();
  } else {
    std::cerr << "Erreur: commande iconnue" << std::endl;
    std::cin.clear();
  }
  return (true);
}

int Annuaire::run(void) {
  std::string cmd = this->_readInput("CMD >> ");
  if (this->_checkCommand(cmd))
    return (run());
  return (0);
}
