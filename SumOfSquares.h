//  Created by Jimmy Kungsman on 2021-12-28.
//  Copyright © 2021 Jimmy Kungsman. All rights reserved.
//

/*
Task
Given a positive integral number n, return a strictly increasing sequence (list/array/string depending on the language) of numbers, so that the sum of the squares is equal to n².

If there are multiple solutions (and there will be), return as far as possible the result with the largest possible values:

Examples
decompose(11) must return [1,2,4,10]. Note that there are actually two ways to decompose 11², 11² = 121 = 1 + 4 + 16 + 100 = 1² + 2² + 4² + 10² but don't return [2,6,9], since 9 is smaller than 10.

For decompose(50) don't return [1, 1, 4, 9, 49] but [1, 3, 5, 8, 49] since [1, 1, 4, 9, 49] doesn't form a strictly increasing sequence.
 */

#ifndef SumOfSquares_h
#define SumOfSquares_h

#include <vector>

using Vec = std::vector<long long>;

class Decomp
{
public:
   static Vec decompose(long long n);
   
private:
   static Vec* decompSqRec(const long long i, const long long tot);
};

Vec Decomp::decompose(long long n)
{
   Vec* seq = decompSqRec(n-1, n*n);
   
   if(seq)
   {
      return *seq;
   }
   
   return {};
}

Vec* Decomp::decompSqRec(const long long i, const long long tot)
{
   if(tot == 0)
      return new std::vector<long long>();
   
   if (i <= 0 || tot < 0)
   {
      return nullptr;
   }
   
   auto* subVec = decompSqRec(i - 1, tot - i*i);
   
   if (subVec)
   {
      subVec->push_back(i);
      return subVec;
   }
   
   return decompSqRec(i - 1, tot);
}

#endif /* SumOfSquares_h */
