#include "./Contact.class.hpp"
#include <cstddef>
#include <iostream>
#include <regex>
#include <string>

bool Contact::_checkInput(const char *input, const char *re) const {
  std::regex r(re);
  std::cmatch m;
  return (std::regex_match(input, m, r));
}

std::string Contact::_readInput(const char *message, const char *re) const {
  std::string input;
  std::cout << message << ": ";
  std::getline(std::cin, input);
  size_t first = input.find_first_not_of(" ");
  size_t last = input.find_last_not_of(" ");
  input = input.substr(first, (last - first + 1));
  if (this->_checkInput(input.c_str(), re)) {
    return (input);
  } else {
    std::cerr << "Erreur: { " << input << " } est au mauvais format"
              << std::endl
              << std::endl;
    std::cin.clear();
    return (this->_readInput(message, re));
  }
}

void Contact::set_attributes(void) {
  this->_first_name = this->_readInput("First Name", "[a-zA-Z- ]+");
  this->_last_name = this->_readInput("Last Name", "[a-zA-Z- ]+");
  this->_nickname = this->_readInput("Nickname", "[a-zA-Z- ]+");
  this->_login = this->_readInput("Login", "[0-9a-zA-Z- _]+");
  this->_birthday_date = this->_readInput("Birthday Date (jj/mm/aaaa)",
                                          "[0-9]{2}/[0-9]{2}/[0-9]{4}");
  this->_phone_number = this->_readInput("Phone Number (xx.xx.xx.xx.xx)",
                                         "([0-9]{2}\\.){4}[0-9]{2}");
  this->_email_address = this->_readInput(
      "Email (example@test.com)", "^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
  this->_postal_address =
      this->_readInput("Postal address (1 rue exemple, 75000 Test)",
                       "([0-9]{1,4} [a-zA-Z0-9- é]+), [0-9]{5} ([A-Z][a-z]+)");
  this->_darkest_secret = this->_readInput("Darkest secret", ".*");
  this->_favorite_meal = this->_readInput("Favorite meal", ".*");
  this->_underwear_color = this->_readInput("Underwear color", "[a-zA-Z ]+");
}

std::string Contact::_truncate(std::string str) const {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}

std::string Contact::get(std::string str) const {
  if (str.compare("first_name") == 0) {
    return (this->_truncate(this->_first_name));
  } else if (str.compare("last_name") == 0) {
    return (this->_truncate(this->_last_name));
  } else if (str.compare("nickname") == 0) {
    return (this->_truncate(this->_nickname));
  }
  return str;
}

void showOneAttribute(const char *name, std::string attribute) {
  std::cout << name << ": " << attribute << std::endl;
}

void Contact::show(void) const {
  showOneAttribute("First name", this->_first_name);
  showOneAttribute("Last name", this->_last_name);
  showOneAttribute("Nick name", this->_nickname);
  showOneAttribute("Login", this->_login);
  showOneAttribute("Birthday date", this->_birthday_date);
  showOneAttribute("Phone number", this->_phone_number);
  showOneAttribute("Email", this->_email_address);
  showOneAttribute("Postal Address", this->_postal_address);
  showOneAttribute("Darkest secret", this->_darkest_secret);
  showOneAttribute("Favorite meal", this->_favorite_meal);
}
