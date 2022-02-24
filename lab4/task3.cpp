#include <iostream>
#include "cat.h"

int main(int argc, char* argv[]) {
    
    int numberOfCats;
    bool missingParam = false;

    //Then it is even because first argument is ./task3
    if (argc % 2 == 1) {
        numberOfCats = argc / 2;
        std::cout << "Number of cats found : " << numberOfCats << std::endl;
    //Then it is odd
    } else {
        numberOfCats = argc / 2;
        std::cout << "Number of cats found : " << numberOfCats << std::endl;
        missingParam = true;
    }

    //Creating a new array of cat objects
    Cat* list_of_cats = new Cat[numberOfCats];

    //Loop through the number of cats and determine their names and lives
    for (int i = 0; i < numberOfCats; i++) {
        
        std::string name;
        unsigned int lives;

        name = argv[2 * i + 1];
        
        if (missingParam == 1 && i == numberOfCats - 1) {
            lives = 9;
        } else {
            lives = atoi(argv[2 * i + 2]);
        }

        Cat newCat(name, lives);
        list_of_cats[i] = newCat;
    }

    //Outputting the Cats to command line
    for (int i = 0; i < numberOfCats; i++) {
        std::cout << list_of_cats[i].get_name() << " has "
                  << list_of_cats[i].get_lives() << " lives." << std::endl;
    }

    //Calling destructor on all cat objects
    for (int i = 0; i < numberOfCats; i++) {
        list_of_cats[i].~Cat();
    }

    return 0;
}