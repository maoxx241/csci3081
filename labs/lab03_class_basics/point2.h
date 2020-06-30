//
//  point2.h
//
//  Created by Qi Mao on 2/3/20.
//  Copyright (c) 2020 Qi Mao. All rights reserved.
//

#ifndef POINT2_H
#define POINT2_H



class Point2 {
public:
    Point2():x(0),y(0) {};
    Point2(double x_,double y_):x(x_),y(y_){};
    virtual ~Point2() {}
    double DistanceBetween(Point2 point);
    int Quadrant();
    void Print();
    double getx(){return x;};
    double gety(){return y;};

private:
    double x;
    double y;
};
#endif 
