/**
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

示例 1：
输入: n = 5, m = 3
输出: 3

示例 2：
输入: n = 10, m = 17
输出: 2
 

限制：
1 <= n <= 10^5
1 <= m <= 10^6

 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
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
     * 暴力解决
     */
    int lastRemaining(int n, int m)
    {
        unordered_set<int> deletedNum;

        int result = -1;
        do {
            for (int i = 0; i < m; i++) {
                do {
                    result += 1;
                    if (result >= n) {
                        result = result - n;
                    }

                } while (deletedNum.count(result) == 1);
            }
            deletedNum.emplace(result);

        } while (deletedNum.size() < n);

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    REQUIRE(s.lastRemaining(5, 3) == 3);
    REQUIRE(s.lastRemaining(10, 17) == 2);
    REQUIRE(s.lastRemaining(1, 17) == 0);
}
