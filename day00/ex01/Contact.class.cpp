#include "./Contact.class.hpp"
#include <iostream>
#include <regex>
#include <string>

bool check_input(const char *input, const char *re) {
  std::regex r(re);
  std::cmatch m;
  return (std::regex_match(input, m, r));
}

void set_one_attribute(t_field field) {
  std::string input;
  std::cout << field.input_message << ": ";
  std::getline(std::cin, input);
  if (check_input(input.c_str(), field.validation)) {
    *field.attribute = input;
  } else {
    std::cerr << "Erreur: { " << input << " } est au mauvais format"
              << std::endl
              << std::endl;
    set_one_attribute(field);
  }
}

t_field *Contact::get_fields(void) {
  static t_field fields[] = {
      {"Veuillez entrer un nom", "[a-zA-Z- ]+", &this->_first_name},
      {"Veuillez entrer un prénom", "[a-zA-Z- ]+", &this->_last_name},
      {"Veuillez entrer un surnom", "[a-zA-Z- ]+", &this->_nickname},
      {"Veuillez entrer une date de naissance (jj/mm/aaaa)",
       "[0-9]{2}/[0-9]{2}/[0-9]{4}", &this->_birthday_date},
      {"Veuillez entrer un login", "[0-9a-zA-Z- _]+", &this->_login},
      {"Veuillez entrer un numéro de téléphone (xx.xx.xx.xx.xx)",
       "([0-9]{2}\\.){4}[0-9]{2}", &this->_phone_number},
      {"Veuillez entrer un email", "^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$",
       &this->_email_address},
      {"Veuillez entrer son plus sombre secret", ".*", &this->_darkest_secret},
      {"Veuillez entrer son repas favori", ".*", &this->_favorite_meal},
      {"Veuillez entrer la couleur de ses sous-vêtements", "[a-zA-Z ]+",
       &this->_underwear_color}

  };
  return (fields);
}

void Contact::set_attributes(void) {
  std::string input;
  t_field *fields = this->get_fields();
  for (int i = 0; i < 10; i++) {
    set_one_attribute(fields[i]);
  }
}
