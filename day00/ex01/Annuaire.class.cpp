
#include "./Annuaire.class.hpp"
#include "Contact.class.hpp"

std::string Annuaire::_prompt(void) const {
  std::string line;
  std::cout << "Veuillez entrer votre commande: ";
  std::getline(std::cin, line);
  return (line);
}

void Annuaire::append(Contact contact) {
  if (this->_contact_index < 4 && this->_contact_index >= 0) {
    this->_contacts[this->_contact_index] = contact;
    this->_contact_index++;
  } else {
    this->_contact_index = 0;
    this->_contacts[0] = contact;
  }
  contact.set_attributes();
}

bool Annuaire::_check_command(std::string cmd) {
  if (cmd.compare("EXIT") == 0) {
    std::cout << "Merci! Au revoir!" << std::endl;
    return (false);
  } else if (cmd.compare("ADD") == 0) {
    Contact contact;
    this->append(contact);
  } else {
    std::cerr << "Erreur: commande iconnue" << std::endl;
  }
  return (true);
}

int Annuaire::run(void) {
  std::string cmd = this->_prompt();
  if (this->_check_command(cmd))
    return (run());
  return (0);
}
