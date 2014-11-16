#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "vecteur.h"
#include <cmath>


using namespace std;

class Point{

private:

    double _x, _y;

public:

    Point(const Point&);
    Point(double x, double y);

    Point translation(const Vecteur& v)const;

    bool operator==(const Point&p)const{
        return (_x == p._x) &&(_y == p._y);
    }

    friend ostream& operator<<(ostream& , const Point &);

    Point getCoordEntieres()const{return Point(round(_x),round(_y));}

    double getX()const{return _x;}
    double getY()const{return _y;}

};



#endif // POINT_H
