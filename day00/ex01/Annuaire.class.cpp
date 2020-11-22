
#include "./Annuaire.class.hpp"

std::string Annuaire::_prompt(void) const {
  std::string line;
  std::cout << "Veuillez entrer votre commande: ";
  std::getline(std::cin, line);
  return (line);
}

bool Annuaire::_check_command(std::string cmd) const {
  if (cmd.compare("EXIT") == 0) {
    std::cout << "Merci! Au revoir!" << std::endl;
    return (false);
  } else {
    std::cerr << "Erreur: commande iconnue" << std::endl;
  }
  return (true);
}

int Annuaire::run(void) const {
  std::string cmd = this->_prompt();
  if (this->_check_command(cmd))
    return (run());
  return (0);
}
