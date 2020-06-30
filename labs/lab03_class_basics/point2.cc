//
// point2.cpp
//
//  Created by Seth Johnson on 2/3/2020.
//  Copyright (c) 2020 Qi Mao. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "point2.h"

using std::cout;
using std::endl;

double Point2::DistanceBetween(Point2 point){
    return sqrt((x-point.getx())*(x-point.getx())+(y-point.gety())*(y-point.gety()));
}

int Point2::Quadrant(){
    if(x>0&&y>=0){
        return 1;
    }else if(x<=0&&y>0){
        return 2;
    }else if(x<0&&y<=0){
        return 3;
    }else if(x>=0&&y<0){
        return 4;
    }else{
        return 0;
    }
}
void Point2::Print(){
    cout<<"x is "<<x<<"\ny is "<<y<<endl;
}