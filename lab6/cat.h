#include <string>
#include <sstream>
#include <functional>
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

    const std::string get_name() const;
    const unsigned int get_lives() const;

    void set_name(std::string name);
    void set_lives(const unsigned int lives);


    friend std::ostream &operator<<(std::ostream &os, const Cat& cat);

    friend bool operator==(const Cat& lhs, const Cat& rhs);

    friend bool operator<(const Cat &lhs, const Cat &rhs);


    ~Cat();
};

namespace std
    {
        template<>
        struct hash <Cat> {
            size_t operator()(const Cat &obj) const {

                unsigned int some_computed_hash;

                std::stringstream sstr;
                sstr << obj;

                std::string newstring = sstr.str();

                std::hash<std::string> hasher;

                some_computed_hash = hasher(newstring);

                return some_computed_hash;

            }
        };
    }
