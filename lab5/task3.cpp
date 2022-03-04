#include <iostream>
#include "Shape.h"

int main(int argc , char *argv[]) {
    Shape **xs = new Shape*[10];

    xs[0] = new Triangle(0, 0, 1, 1, 0, 1);
    xs[1] = new Circle(0, 0, 1);
    xs[2] = new Rectangle(0, 0, 1, 1);
    xs[3] = new Circle(1, 3, 2);
    xs[4] = new Circle(3, 5, 4);
    xs[5] = new Triangle(3, 3, 10, 3, 10, 7);
    xs[6] = new Rectangle(2, 2, 4, 6);
    xs[7] = new Rectangle(0, 2, 6, 4);
    xs[8] = new Circle(4, 4, 1);
    xs[9] = new Triangle(1, 1, 2, 2, 1, 2);


    for (int i = 0; i < 10; i++) {
        std::cout << xs[i]->to_string() << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        xs[i]->centre_at(-2.5, 2.5);
    }
        
    for (int i = 0; i < 10; i++) {
        std::cout << xs[i]->to_string() << std::endl;
    }
    
    delete xs;
    return 0;
}