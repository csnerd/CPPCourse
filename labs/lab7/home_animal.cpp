#include "animal.h"

int HomeAnimal::_count = 0;

HomeAnimal::HomeAnimal():_name(""), _eat(0){

}

HomeAnimal::HomeAnimal(std::string name,int eat):_name(name),_eat(eat){

}
std::string HomeAnimal::say() const {
    return "I am a wild "+_name+", I have 4 legs and I feeded "+std::to_string(_eat)+" kg";
}
std::string HomeAnimal::type() const {
    return "wild";
}
void HomeAnimal::eat(double kg){
    _eat = kg;
}
int HomeAnimal::count() const{
    return _count;
}
HomeAnimal::~HomeAnimal(){
    --_count;
}