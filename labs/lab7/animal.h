#pragma once
#include <iostream>
#include <string>
#include <map>

class Animal {
  public:
  virtual std::string say() const = 0;
  virtual std::string type() const = 0;
  virtual void eat(double kg) = 0;
  virtual int count() const = 0;
  virtual ~Animal() = default;
};

class WildAnimal : public Animal{
public:
  std::string say() const ;
  std::string type() const ;
  void eat(double kg);
  int count() const;
  WildAnimal();
  WildAnimal(const std::string name,int eat);
  ~WildAnimal();

public:
  std::string _name;
  int         _eat;
  static int  _count;
};



class HomeAnimal : public Animal{
  public:

  std::string say() const ;
  std::string type() const ;
  void eat(double kg);
  int count() const;
  HomeAnimal();
  HomeAnimal(const std::string name,int eat);
  ~HomeAnimal();

public:
  std::string _name;
  int         _eat;
  static int  _count;
};

class AnimalConter {
  public:
  void add_animal(const std::string& animal);
  void remove_animal(const std::string& animal);
  size_t count_of_animals(const std::string& animal) const;
  static AnimalConter& instance();
  private:
  std::map<std::string, size_t> animals_;
};

