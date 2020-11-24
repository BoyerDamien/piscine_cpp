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
