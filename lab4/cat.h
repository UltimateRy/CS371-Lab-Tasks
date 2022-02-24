#include <string>
#pragma once

class Cat
{
private:
    std::string name;
    unsigned int lives;

public:

    Cat();
    Cat(std::string name);
    Cat(std::string name, unsigned int lives);

    const std::string get_name();
    const unsigned int get_lives();

    void set_name(std::string name);
    void set_lives(const unsigned int lives);

    ~Cat();
};