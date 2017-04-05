//  Created by Jimmy Kungsman on 2017-04-03.
//  Copyright © 2017 Jimmy Kungsman. All rights reserved.

#include <iostream>
#include <vector>
using namespace std;

// Greatest common divisor
int gcd(int a, int b){
    return (b == 0) ? a : gcd(b, a%b);
}

// Factorial
int factorial(int n){
    return (n == 0) ? 1 : n*factorial(n-1);
}

// Selects the two biggest numbers from an int vector on O(n) time
void twoMax(vector <int> v){
    int max, max2;
    
    if(v[0] > v[1]){
        max = v[0];
        max2 = v[1];
    }
    else{
        max = v[1];
        max2 = v[0];
    }
    
    for(int i : v){
        if(i > max){
            max2 = max;
            max = i;
        }
        else if(i > max2){
            max2 = i;
        }
    }
    cout << "Largest value: " << max << endl;
    cout << "Second largest value: " << max2 << endl;
}
