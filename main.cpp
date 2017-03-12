#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Test whether a word is a palindrome or not.
bool isPalindrome(string word){
    
    string reverseWord;
    
    unsigned long length = word.length();
    
    for(int i=0; i<length; i++){
        reverseWord.push_back(word[length - 1 - i]);
    }
    
    if(strcmp(word.c_str(), reverseWord.c_str()) == 0) return true;
    return false;
}

void testPalindrome(){
    while(true){
        string testWord;
        string tmp;
        string welcome = "Ange ordet du vill testa:";
        
        cout << welcome << endl;
        
        cin >> testWord;
        
        isPalindrome(testWord);
        
        string ans = isPalindrome(testWord) ? "It is" : "It isn't";
        
        cout << ans << endl;
    }
}


// Removing a given character from a given string.
void removeChar(string *s, char c){
    (*s).erase(remove((*s).begin(), (*s).end(), c), (*s).end());
}

void printAllPerm1(string s){
    do{
        cout << s << endl;
    }
    while( next_permutation(s.begin(), s.end()) );
}

// Finding the longest palindrome of a given string.
int longestPalindrome(string s){
    int maxLength = 1;
    
    int length = (int)s.length();
    
    for(int i=0; i< length; i++){
        for(int j=length-1; j>i; j--){
            if(isPalindrome(s.substr(i,j-i+1)) && j-i+1>maxLength) maxLength = j-i+1;
        }
    }
    return maxLength;
}

// Finding the first non-repetitive character of a given string.
void firstNonRepetitiveChar(string s){
    int length = (int)s.length();
    char firstChar = s.at(0);
    string subString = s.substr(1);
    
    if(length > 0){
        
        if(subString.find(firstChar) == std::string::npos){
            cout << "Första är " << firstChar << endl;
            return;
        }
        
        subString.erase( remove(subString.begin(), subString.end(), firstChar), subString.end() );
        
        firstNonRepetitiveChar(subString);
    }
    else{
        cout << "Alla bokstäver upprepar sig." << endl;
    }
}

// Given an array containing a certain stock price variation throughout a day
// this algorithm will calculate the optimal profit that could have been
// made given that purchase must proceed selling.
void getMaxProfit(){
    int stockPrices[] = {10, 7, 5, 8, 11, 9}; //just example
    
    int bestProfit = stockPrices[1] - stockPrices[0];
    int minPrice = stockPrices[0];
    int length = sizeof(stockPrices) / sizeof(stockPrices[0]);
    
    for(int i=1; i<length; i++){
        int potentialProfit = stockPrices[i] - minPrice;
        
        minPrice = (minPrice > stockPrices[i]) ? stockPrices[i] : minPrice;
        
        if(potentialProfit > bestProfit){
            bestProfit = potentialProfit;
        }
    }
    
    cout << "Best profit is " << bestProfit << endl;
    
}

// Given a vector of integers this function produces another vector of the
// same size where the i:th entry contains the product of all elements except
// the one at the given index of the original vector (without ever using
// division).
vector<int> getProdOfAllIntExceptIndex(const vector<int> randVec){
    int length = (int)randVec.size();
    vector<int> prodVec(length);
    
    int tempProd = 1;
    
    for(int i=0; i<length; i++){
        prodVec[i] = tempProd;
        tempProd *= randVec[i];
    }
    
    tempProd = 1;
    
    for(int i=length-1; i>=0; i--){
        prodVec[i] *= tempProd;
        tempProd *= randVec[i];
    }
    return prodVec;
}

// Solution to finding the largest product of 3 integers from a collection
// of integers.
int maxProd3Integers(vector<int> randArr){
    int length = (int)randArr.size();
    
    int maxProd3 = randArr[0]*randArr[1]*randArr[2];
    int maxProd2 = randArr[0]*randArr[1];
    int minProd2 = randArr[0]*randArr[1];
    int maxInt = randArr[0];
    int minInt = randArr[0];
    
    for(int i=2; i<length; i++){
        int current = randArr[i];
        
        maxProd3 = max(max(maxProd2 * current, maxProd3), minProd2 * current);
        
        maxProd2 = max(max(current * maxInt, current * minInt), maxProd2);
        
        minProd2 = min(min(current * maxInt, current * minInt), minProd2);
        
        maxInt = max(current, maxInt);
        
        minInt = min(current, minInt);
    }
    
    return maxProd3;
}

// Bubble sort algorithm for sorting integers from smallest to largest
vector<int> bubbleSortAscending(vector<int> intVector){
    
    for(int i=0; i<intVector.size()-1; i++){
        for(int j=i+1; j<intVector.size(); j++){
            if(intVector[i] > intVector[j]){
                int tmp = intVector[j];
                intVector[j] = intVector[i];
                intVector[i] = tmp;
            }
        }
    }
    return intVector;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
