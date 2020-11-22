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
  void set_attributes(void);
  struct s_field *get_fields(void);
};

typedef struct s_field {
  const char *input_message;
  const char *validation;
  std::string *attribute;
} t_field;

#endif
