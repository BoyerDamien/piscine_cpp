#include "./Annuaire.class.hpp"
#include "./Contact.class.hpp"
#include <string>

int main(int argc, char **argv) {
  // Annuaire app = Annuaire();
  // return (app.run());
  Contact damien;
  std::cout << damien.set_phone_number("06.07.99.06.11") << std::endl;
  return (0);
}
