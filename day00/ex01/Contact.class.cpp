/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:25:51 by dboyer            #+#    #+#             */
/*   Updated: 2020/12/03 16:04:32 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.class.hpp"
#include <cstddef>
#include <iostream>
#include <string>

static std::string ft_str_trim(std::string str, char c) {
  size_t first = str.find_first_not_of(c);
  size_t last = str.find_last_not_of(c);
  if (first != std::string::npos && last != std::string::npos)
    return str.substr(first, (last - first + 1));
  return "";
}

std::string Contact::_readInput(const char *message) const {
  std::string input;
  std::cout << message << ": ";
  std::getline(std::cin, input);
  std::cin.clear();
  return ft_str_trim(input, ' ');
}

void Contact::set_attributes(void) {
  this->_first_name = this->_readInput("First Name");
  this->_last_name = this->_readInput("Last Name");
  this->_nickname = this->_readInput("Nickname");
  this->_login = this->_readInput("Login");
  this->_birthday_date = this->_readInput("Birthday Date");
  this->_phone_number = this->_readInput("Phone Number");
  this->_email_address = this->_readInput("Email");
  this->_postal_address = this->_readInput("Postal address");
  this->_darkest_secret = this->_readInput("Darkest secret");
  this->_favorite_meal = this->_readInput("Favorite meal");
  this->_underwear_color = this->_readInput("Underwear color");
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
