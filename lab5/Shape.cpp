#include "Shape.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>

Shape::Shape(){
    //std::cout << "Constructor called for shape." << std::endl;
};

Shape::~Shape(){
    //std::cout << "Destructor called for shape." << std::endl;
};

//Implementing the circle constructor, destructor and methods:

Circle::Circle(double x, double y, double r) : Shape() {
    this->x = x;
    this->y = y;
    this->r = r;
    //std::cout << "Constructor called for circle." << std::endl;
}

Circle::~Circle() {
    //std::cout << "Destructor called for circle." << std::endl;
}

void Circle::centre_at(double x, double y) {
    this->x = x;
    this->y = y;
    //std::cout << "Center changed" << std::endl;
}

std::string Circle::to_string() const {
    std::stringstream sstr;
    sstr << "A circle at (" << this->x << "," << this->y << ") with radius " << this->r;
    std::string string = sstr.str();
    return string;
}

//Implementing the rectangle constructor, destructor and methods:

Rectangle::Rectangle(double x0, double y0, double x1, double y1) : Shape() {

    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;

    //std::cout << "Constructor called for rectangle." << std::endl;
}

Rectangle::~Rectangle() {
    //std::cout << "Destructor called for rectangle." << std::endl;
}

std::string Rectangle::to_string() const {

    std::stringstream sstr;

    sstr << "A rectangle at [(" << this->x0 << "," << this->y0 << "), " 
    << "(" << this->x1 << "," << this->y1 << ")] with width " << (this->x1 - this->x0)
    << ", height " << (this->y0 - this->y1);

    std::string string = sstr.str();
    return string;
}

void Rectangle::centre_at(double x, double y) {

    double width = this->x1 - this->x0;
    double height = this->y0 - this->y1;

    double half_width = width / 2;
    double half_height = height / 2;

    this->x0 = x - half_width;
    this->y0 = y + half_height;
    this->x1 = x + half_width;
    this->y1 = y - half_height;

    //std::cout << "Center changed" << std::endl;
}

//Implementing the triangle constructor, destructor and methods:

Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2) : Shape() {

    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;

    //std::cout << "Constructor called for triangle." << std::endl;
}

Triangle::~Triangle() {
    //std::cout << "Destructor called for rectangle." << std::endl;
}

std::string Triangle::to_string() const {
    double side_0 = sqrt( pow((x2 - x0),2) + pow((y2 - y0) , 2) );
    double side_1 = sqrt( pow((x2 - x1),2) + pow((y1 - y2) , 2) );
    double side_2 = sqrt( pow((x1 - x0),2) + pow((y1 - y0) , 2) );
    
    std::stringstream sstr;

    sstr << "A triangle at [(" << this->x0 << "," << this->y0 << "), " 
    << "(" << this->x1 << "," << this->y1 << "), "
    << "(" << this->x2 << "," << this->y2 << ")] with side lengths "
    << side_0 << ", " << side_1 << " and " << side_2;

    std::string string = sstr.str();
    return string;
}

void Triangle::centre_at(double x, double y) {

    double centroid_x = (x0 + x1 + x2) / 3;
    double centroid_y = (y0 + y1 + y2) / 3;

    double shift_x = centroid_x - x;
    double shift_y = centroid_y - y;

    this->x0 -= shift_x;
    this->y0 -= shift_y;
    this->x1 -= shift_x;
    this->y1 -= shift_y;
    this->x2 -= shift_x;
    this->y2 -= shift_y;

    //std::cout << "Center changed" << std::endl;
}