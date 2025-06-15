#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Comparison.h"
#include "Point.h"

using namespace std;

template <typename T, typename U>
void randomize_Point(Point<T, U>&);

template <typename T, typename U>
void randomize_Point(Point<T,U>&, T, T);

int main() {
    srand(time(NULL));
    Point<int,double> p(10.5,20);
    cout << "Point1_ przed random: ";
    p.show();
    Point<int,double> p2(10.1,20);
    cout << "Point2_ przed random: ";
    p2.show();
    randomize_Point(p);
    cout << "Point1_ po random: ";
    p.show();
    randomize_Point<int,double>(p2, 1, 5);
    cout << "Point2_ po random: ";
    p2.show();
    Comparison<int,double> comp(p,p2);
    comp.show_all();
    std::move(p);

    return 0;
}

template <typename T, typename U>
void randomize_Point(Point<T, U>& CurrentPoint) {
    CurrentPoint.setX(((float)rand() / RAND_MAX) * 50);
    CurrentPoint.setY(((float)rand() / RAND_MAX) * 50);
}

template <typename T, typename U>
void randomize_Point(Point<T,U>& CurrentPoint, T start, T end) {
    CurrentPoint.setX(((float)rand() / RAND_MAX) * (end - start) + start);
    CurrentPoint.setY(((float)rand() / RAND_MAX) * (end - start) + start);
}

