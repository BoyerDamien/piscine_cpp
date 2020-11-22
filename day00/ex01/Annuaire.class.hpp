#ifndef ANNUAIRE_CLASSS_H
#define ANNUAIRE_CLASSS_H
#include <iostream>

class Annuaire {

private:
  std::string _prompt(void) const;
  bool _check_command(std::string) const;

public:
  int run(void) const;
};

#endif
