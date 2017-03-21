//  Simulating an approximation of pi by placing random points inside
//  a unit square and counting those that fall within radius 1.
//  Created by Jimmy Kungsman on 2017-03-21.
//  Copyright © 2017 Jimmy Kungsman. All rights reserved.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<double> randPoint(){
    vector<double> pt(2);
    
    double xPos = (double) rand() / RAND_MAX;
    double yPos = (double) rand() / RAND_MAX;
    pt.at(0) = xPos;
    pt.at(1) = yPos;
    return pt;
}

bool isInsideCircle(vector<double> pt){
    double xPos = pt.at(0);
    double yPos = pt.at(1);
    double radius = sqrt(xPos*xPos + yPos*yPos);
    
    if(radius < 1){return true;}
    else {return false;}
}

int main(int argc, const char * argv[]) {
    
    int countInside = 0;
    int totCount = 1000000;
    double piApprox;
    
    for(int i=0; i<totCount; i++){
        vector<double> point = randPoint();
        if(isInsideCircle(point)){countInside++;}
    }
    
    piApprox = 4 * ((double)countInside / totCount);
    
    cout << piApprox << endl;
    return 0;
}
