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
     * 只要校验字符串长度的最大公约数前缀是否满足要求即可
     * https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/zi-fu-chuan-de-zui-da-gong-yin-zi-by-leetcode-solu/
     * 方法二
     */
    string gcdOfStrings(string str1, string str2)
    {
        // std::gcd() in numeric since c++17 , compile with clang++ -std=c++17
        int gcdSize = gcd((int)str1.size(), (int)str2.size());
        string substr = str1.substr(0, gcdSize);

        if (check(str1, substr) && check(str2, substr))
        {
            return substr;
        }
        return "";
    }

    /**
     * 校验S是否能拼接成T
     */
    bool check(string T, string s)
    {
        int count = (int)(T.size() / s.size());
        string ans = "";
        for (int i = 0; i < count; i++)
        {
            ans += s;
        }
        return T == ans;
    }
};