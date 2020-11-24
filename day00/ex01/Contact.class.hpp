#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact {

private:
  std::string _first_name;
  std::string _last_name;
  std::string _nickname;
  std::string _login;
  std::string _postal_address;
  std::string _email_address;
  std::string _phone_number;
  std::string _birthday_date;
  std::string _favorite_meal;
  std::string _underwear_color;
  std::string _darkest_secret;
  bool _checkInput(const char *, const char *) const;
  std::string _readInput(const char *, const char *) const;
  std::string _truncate(std::string) const;

public:
  void set_attributes(void);
  void show(void) const;
  std::string get(std::string) const;
};
#endif
