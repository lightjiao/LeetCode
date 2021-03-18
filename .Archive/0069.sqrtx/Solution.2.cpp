/**
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../TreeNode.cpp"
#include "../VV.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 暴力梭哈，一个一个试出来
     */
    int mySqrt(int x)
    {
        int n = (x >> 1) + 2;
        for (long i = 0; i < n; i++)
        {
            long s = i * i;
            if (s == x)
            {
                return i;
            }
            if (s > x)
            {
                return i - 1;
            }
        }

        return 0;
    }
};

TEST_CASE("test")
{
    Solution s;

    REQUIRE(s.mySqrt(1) == 1);
    REQUIRE(s.mySqrt(2) == 1);
    REQUIRE(s.mySqrt(3) == 1);
    REQUIRE(s.mySqrt(4) == 2);
    REQUIRE(s.mySqrt(8) == 2);
    REQUIRE(s.mySqrt(2147395599) == 46339);
    REQUIRE(s.mySqrt(2147483647) == 46340);
}
