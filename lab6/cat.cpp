#include "cat.h"
#include <string>
#include <iostream>

Cat::Cat() {
    //std::cout << "Default Constructor called" << std::endl;
    name = "Tom";
    lives = 9;
}

Cat::Cat(std::string name) : name(name), lives(9) {
    //std::cout << "Constructor called with name " << name << std::endl;
}

Cat::Cat(std::string name, unsigned int lives) : name(name), lives(lives) {
    //std::cout << "Constructor called with name " << name << " and lives : " << lives << std::endl;
}

const std::string Cat::get_name() const{
    return name;
}  
const unsigned int Cat::get_lives() const{
    return lives;
}

void Cat::set_name(const std::string name) {
    this->name = name;
    std::cout << "Set name called with name " << name << std::endl;

}

void Cat::set_lives(const unsigned int lives) {

    std::cout << "Set lives called with lives " << lives << std::endl;

    
    if (this->lives > 0 && lives == 0) {
        set_name("The cat formerly known as " + get_name());
    }

    if (this->lives > lives) {
        this->lives = lives;
    }

    return;  
}

std::ostream &operator<<(std::ostream &os, const Cat& cat) {

    os << cat.get_name() << " has " << cat.get_lives() << " lives";
    return os;
}

bool operator==(const Cat& lhs, const Cat& rhs) {

    if ((lhs.get_name() == rhs.get_name()) && (lhs.get_lives() == rhs.get_lives())) {
        return true;
    } else {
        return false;
    }

}

bool operator<(const Cat &lhs, const Cat &rhs) {

    if (lhs.get_name() < rhs.get_name()) {
        return 1;
    } else if (lhs.get_name() == rhs.get_name()) {
        if (lhs.get_lives() < rhs.get_lives()) {
            return 1;
        } else {
            return 0;
        }
    } else if (lhs.get_name() > rhs.get_name()) {
        return 0;
    }

    return 1;
}

Cat::~Cat() {
    //std::cout << "Destructor called for name " << name << std::endl;
}


