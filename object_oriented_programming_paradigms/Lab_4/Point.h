//
// Created by Maciej Polanowski on 09/05/2025.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;

template <class T, class U>
class Point {
    T x_;
    U y_;
public:
    Point(T x, U y) : x_(x), y_(y) {}
    ~Point() {}
    T getX() const { return x_; }
    U getY() const { return y_; }
    void setX(T x) { x_ = x; }
    void setY(U y) { y_ = y; }
    void show() const;
};

template<class T, class U>
void Point<T, U>::show() const {
    cout << "Coordinates: (" << getX() << ", " << getY() << ")" << endl;
}


#endif //POINT_H
