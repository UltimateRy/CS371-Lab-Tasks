#include <string>
#pragma once

class Shape 
{
public:
    Shape();

    virtual std::string to_string() const = 0;
    virtual void centre_at(double x, double y) = 0;

    virtual ~Shape();
};

struct Circle : public Shape {

    double x,y,r;

    Circle(double x, double y, double r);

    virtual ~Circle();

    virtual std::string to_string() const;

    virtual void centre_at(double x, double y);

};

struct Rectangle : public Shape {

    double x0, y0, x1, y1;

    Rectangle(double x0, double y0, double x1, double y1);

    virtual ~Rectangle();

    virtual std::string to_string() const;

    virtual void centre_at(double x, double y);

};

struct Triangle : public Shape {

    double x0, y0, x1, y1, x2, y2;

    Triangle(double x0, double y0, double x1, double y1, double x2, double y2);

    virtual ~Triangle();

    virtual std::string to_string() const;

    virtual void centre_at(double x, double y);

};