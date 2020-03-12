#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "limits.h"
#include <numeric>

using namespace std;

class Solution
{
public:
    /**
     * 需要知道一个性质：如果 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串 X。
     */
    string gcdOfStrings(string str1, string str2)
    {
        // std::gcd() in numeric since c++17 , compile with clang++ -std=c++17
        if (str1 + str2 != str2 + str1)
        {
            return "";
        }
        
        return str1.substr(0, gcd((int)str1.size(), (int)str2.size()));
    }
};