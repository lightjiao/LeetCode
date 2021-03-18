/**
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> m;
        for (auto&& c : s) {
            m[c]++;
        }

        int  result  = 0;
        bool oneFlag = true;
        for (auto&& kv : m) {
            while (kv.second >= 2) {
                kv.second -= 2;
                result += 2;
            }

            if (oneFlag && kv.second > 0) {
                oneFlag = false;
                kv.second--;
                result++;
            }
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.longestPalindrome("abccccdd") == 7);
    REQUIRE(s.longestPalindrome("aaaAaaaa") == 7);
}