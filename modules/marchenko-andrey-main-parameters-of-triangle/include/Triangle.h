// Copyright 2016 Marchenko Andrey

#ifndef MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
#define MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_

#include <stdexcept>

class ThreeSamePoints :public std::runtime_error {
 public:
     ThreeSamePoints() : std::
         runtime_error("Triangle is not correct, three points are idential") {}
};

class TwoSamePoints :public std::runtime_error {
 public:
     TwoSamePoints() : std::
         runtime_error("Triangle is not correct, two points are idential") {}
};

class IncorrectPoints :public std::runtime_error {
 public:
     IncorrectPoints() : std::
         runtime_error("Triangle is not correct, all points on one line") {}
};

struct point{
    double x;
    double y;

    point();
    point(const double A, const double B);
    point(const point &A);

    bool operator==(const point& p) const;
};

class Triangle{
 public:
    Triangle();
    Triangle(const point A, const point B, const point C);
    Triangle(const Triangle &T);

    point get_A() const;
    point get_B() const;
    point get_C() const;

    void set_A(const point A);
    void set_B(const point B);
    void set_C(const point C);

    int is_triangle_correct(point A, point B, point C);

    bool operator==(const Triangle& T1) const;

    double triangle_side_length(const point first_point,
        const point second_point) const;
    double angle_A_of_triangle_in_radians() const;
    double angle_B_of_triangle_in_radians() const;
    double angle_C_of_triangle_in_radians() const;
    double perimeter_of_triangle() const;
    double area_of_triangle() const;
    double inradius() const;
    double circumradius() const;

 private:
    point A;
    point B;
    point C;
};

#endif  // MODULES_MARCHENKO_ANDREY_MAIN_PARAMETERS_OF_TRIANGLE_INCLUDE_TRIANGLE_H_
