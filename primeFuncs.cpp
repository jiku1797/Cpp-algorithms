//  Created by Jimmy Kungsman on 2017-03-29.
//  Copyright © 2017 Jimmy Kungsman. All rights reserved.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//  Modifies a vector to contain prime factors of a given integer
void getPrimes(int a, vector <int>* rPrimeList){
    for(int i=2; i<=a; i++){
        if((a % i) == 0){
            (*rPrimeList).push_back(i);
            a /= i;
            if(a == 1){
                return;
            }
            else{
                break;
            }
        }
    }
    getPrimes(a, rPrimeList);
}

//  Returns a vector of all prime factorizations up to a given limit
vector <vector <int>> primeListsUpTo(int n){
    vector <vector <int>> totList;
    for(int i=2; i<=n; i++){
        vector<int> singleList;
        getPrimes(i, &singleList);
        totList.push_back(singleList);
    }
    return totList;
}

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

// Returns a vector of all primes less than a given limit
vector <int> primesLessThan(int n){
    vector <int> v;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            v.push_back(i);
        }
    }
    return v;
}

int main() {
    
}
