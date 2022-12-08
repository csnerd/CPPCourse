#pragma once
#include "animal_factory.h"

class HomeAnimalFactory : public AnimalFactory {
  public:
  Animal* create(const std::string sort) override;
};