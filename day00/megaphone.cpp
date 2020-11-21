#include <bits/c++config.h>
#include <cctype>
#include <iostream>
#include <string>

std::string ft_toupper(std::string str) {
  std::string ret = "";
  for (size_t i = 0; i < str.length(); i++) {
    ret.push_back(std::toupper(str[i]));
  }
  return (ret);
}

std::string ft_str_trim(std::string str, char c) {
  size_t first = str.find_first_not_of(c);
  size_t last = str.find_last_not_of(c);
  return (str.substr(first, (last - first + 1)));
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  } else {
    std::string output = "";
    for (int i = 0; i < argc; i++) {
      output += ft_str_trim(ft_toupper(argv[i]), ' ');
      if (i < argc - 1)
        output += " ";
    }
    std::cout << output << std::endl;
  }
}
