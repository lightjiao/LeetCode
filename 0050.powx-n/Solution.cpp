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
     * x^n = e^(nlogx), 注意结果的正负号即可
     */
    double myPow(double x, int n)
    {
        bool minus = (x < 0) && (n & 1) == 1;

        x = abs(x);
        return minus ? -exp(n * log(x)) : exp(n * log(x));
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
