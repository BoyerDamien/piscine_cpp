#include "./Contact.class.hpp"
#include <regex>

static t_field FIELDS[11] = {

};

bool check_input(const char *input, const char *re) {
  std::regex r(re);
  std::cmatch m;
  return (std::regex_match(input, m, r));
}

bool Contact::set_birthday_date(const char *input) {
  if (check_input(input, "[0-9]{2}/[0-9]{2}/[0-9]{4}")) {
    this->_birthday_date = input;
    return (true);
  } else {
    return (false);
  }
}

bool Contact::set_email(const char *input) {
  if (check_input(input, "^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$")) {
    this->_email_address = input;
    return (true);
  } else {
    return (false);
  }
}

bool Contact::set_phone_number(const char *input) {
  if (check_input(input, "([0-9]{2}\\.){4}[0-9]{2}")) {
    this->_phone_number = input;
    return (true);
  } else {
    return (false);
  }
}

void Contact::set_attribute(void) {
  const char **labels = {"firs"};
  for (const char *l : labels) {
  }
}
