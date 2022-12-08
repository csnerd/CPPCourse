#pragma once
#include "animal_factory.h"

class WildAnimalFactory : public AnimalFactory {
  public:
  Animal* create(const std::string) override;
};