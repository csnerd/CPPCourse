#include "wild_animal_factory.h"

Animal* WildAnimalFactory::create(const std::string sort) {
    Animal* a = new WildAnimal(sort,0);
    AnimalConter::instance().add_animal(sort);

    return a;
}