#include "animal.h"

int WildAnimal::_count = 0;

WildAnimal::WildAnimal():_name(""), _eat(0){

}

WildAnimal::WildAnimal(const std::string name,int eat):_name(name),_eat(eat){

}
std::string WildAnimal::say() const {
    return "I am a wild "+_name+", I have 4 legs and I feeded "+std::to_string(_eat)+" kg";
}
std::string WildAnimal::type() const {
    return "wild";
}
void WildAnimal::eat(double kg){
    _eat = kg;
}
int WildAnimal::count() const{
    return _count;
}
WildAnimal::~WildAnimal() {
    --_count;
}