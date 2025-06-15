//
// Created by Maciej Polanowski on 02/05/2025.
//

#ifndef COMPARISON_H
#define COMPARISON_H

#include "Point.h"
#include <iostream>
#include <cmath>
constexpr float PI = 3.14159265358979323846;

using namespace std;


template <class T, class U>
class Comparison {
    Point<T,U> Point1_;
    Point<T,U> Point2_;
    T solution_;
public:
    Comparison(Point<T,U> p1, Point<T,U> p2): Point1_(p1), Point2_(p2) {
        /*cout << "Comparison constructor" << endl;*/
    }

    ~Comparison() {
        /*cout << "Comparison destructor" << endl;*/
    }

    Point<T,U> get_Point1() const {
        return Point1_;
    }

    void set_Point1(Point<T,U> p1) {
        Point1_ = p1;
    }

    Point<T,U> get_Point2() const {
        return Point2_;
    }

    T get_Solution() const {
        return solution_;
    }

    void show_cords();
    void distance();
    Point<T,U> mid_point(const Point<T,U>&, const Point<T,U>&);
    float circumference();
    void show_all();
    Point<T,U> move();
};

template<class T, class U>
void Comparison<T, U>::show_cords() {
    cout << "Point1: (" << Point1_.getX() << ", " << Point1_.getY() << ")" << endl;
    cout << "Point2: (" << Point2_.getX() << ", " << Point2_.getY() << ")" << endl;
}

template<class T, class U>
void Comparison<T, U>::distance() {
    solution_ = sqrt(pow(Point2_.getX()-Point1_.getX(),2)+pow(Point2_.getY()-Point1_.getY(), 2));
}

template<typename T, typename U>
Point<T, U> Comparison<T, U>::mid_point(const Point<T, U> &p1, const Point<T, U> &p2) {
    T x=(p1.getX()+p2.getX())/2;
    U y=(p1.getY()+p2.getY())/2;
    Point<T,U> center(x,y);
    return center;
}

template<class T, class U>
float Comparison<T, U>::circumference() {
    distance();
    return PI*solution_;
}

template<class T, class U>
void Comparison<T, U>::show_all() {
    cout << "Cords:\n ";
    show_cords();
    cout << "Distance: ";
    distance();
    cout << get_Solution() << endl;
    cout << "Center ";
    mid_point(get_Point1(), get_Point2()).show();
    cout << "Circumference: ";
    cout << circumference() << endl;
    cout << "Move ";
    move().show();
    show_cords();
}

template<class T, class U>
Point<T,U> Comparison<T, U>::move() {
    Point<T,U> center = mid_point(get_Point1(), get_Point2());
    Point<T,U> moved_point = mid_point(get_Point1(), center);
    set_Point1(moved_point);
    return moved_point;
}




#endif //COMPARISON_H
