#pragma once

class Cat
{
private:
    std::string name;
    unsigned int lives;

public:

    Cat(std::string name);

    Cat(std::string name, unsigned int lives);

    const std::string get_name() { return name; }

    const int get_lives() { return lives; }


    ~Cat();

};