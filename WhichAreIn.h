//Kata from Codewars

//Given two arrays of strings a1 and a2 return a sorted array r in lexicographical
//order of the strings of a1 which are substrings of strings of a2.

#ifndef WHICHAREIN_H
#define WHICHAREIN_H

#include <algorithm>
#include <string>
#include <vector>

class WhichAreIn
{
  public:
  static std::vector<std::string> inArray(const std::vector<std::string> &array1, const std::vector<std::string> &array2);
};

std::vector<std::string> WhichAreIn::inArray(const std::vector<std::string> &array1, const std::vector<std::string> &array2)
{
  std::vector<std::string> res;

  std::copy_if(std::begin(array1), std::end(array1), std::back_inserter(res), [&array2](const std::string str1)
    {
      return std::any_of(std::begin(array2), std::end(array2), [&str1](const std::string str2)
      {
        return (str2.find(str1) != std::string::npos);
      });
    }
  );

  std::sort(std::begin(res), std::end(res), std::less<std::string>());

  return res;
}

#endif // WHICHAREIN_H
