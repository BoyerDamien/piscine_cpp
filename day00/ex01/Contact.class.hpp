#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

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

public:
  bool set_email(const char *);
  bool set_phone_number(const char *);
  bool set_birthday_date(const char *);
  void set_attribute(void);
};

typedef struct s_field {
  const char *input_message;
  const char *validation;
  std::string Contact::*attribute;
} t_field;

#endif
