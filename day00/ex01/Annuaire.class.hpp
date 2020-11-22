#ifndef ANNUAIRE_CLASSS_H
#define ANNUAIRE_CLASSS_H
#include "./Contact.class.hpp"
#include <iostream>

class Annuaire {

private:
  Contact _contacts[4];
  int _contact_index;

  std::string _prompt(void) const;
  bool _check_command(std::string);

public:
  int run(void);
  void append(Contact);
};

#endif
