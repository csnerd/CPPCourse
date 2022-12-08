#include "animal.h"

AnimalConter& AnimalConter::instance() {
  static AnimalConter instance;
  return instance;
}

void AnimalConter::add_animal(const std::string& animal) {
  animals_[animal] += 1;
}

void AnimalConter::remove_animal(const std::string& animal) {
  animals_[animal] -= 1;
}
size_t AnimalConter::count_of_animals(const std::string& animal) const {
  auto it = animals_.find(animal);
  if (animals_.end() != it) {
    return it->second;
  }
  return 0;
}
