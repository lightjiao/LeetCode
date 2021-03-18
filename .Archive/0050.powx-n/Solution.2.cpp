/**
实现 pow(x, n) ，即计算 x 的 n 次幂函数。
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
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 快速幂 + 递归
     * 什么是快速幂:
     * 比如求
     * x^64: x -> x^2 -> x^4 -> x^8 -> x^16 -> x^32 -> x^64
     * x^77: x -> x^2 -> x^4 -> x^9 -> x^19 -> x^38 -> x^77
     */
    double myPow(double x, int n)
    {
        long long N = n;

        // x^n = 1/(x^n)
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

    double quickMul(double x, long long N)
    {
        if (N == 0)
        {
            return 1.0;
        }

        double y = quickMul(x, N / 2);

        return (N & 1) == 0 ? y * y : y * y * x;
    }
};

TEST_CASE("test")
{
    Solution s;

    REQUIRE(s.myPow(2.00000, 0) == 1);
    // REQUIRE(s.myPow(0, 0) == 0);
    REQUIRE(s.myPow(0, 2) == 0);
    REQUIRE(s.myPow(2.00000, 10) == 1024.00000);
    REQUIRE(s.myPow(2.10000, 3) == 9.26100);
    REQUIRE(s.myPow(2.00000, -2) == 0.25000);
    REQUIRE(s.myPow(-2.00000, 2) == 4.0);
}
