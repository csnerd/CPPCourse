#pragma once
#include "animal.h"

class AnimalFactory {
  public:
  virtual Animal* create(const std::string) = 0;
};
