/**
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

提示：
1 <= deck.length <= 10000
0 <= deck[i] < 10000
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../VV.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>  // std::gcd() since c++17
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
    // x >= 2
    bool hasGroupsSizeX(vector<int>& deck)
    {
        if (deck.size() < 2) {
            return false;
        }

        // 统计所有的数字, 对数字个数求公约数, 公约数即为x
        unordered_map<int, int> countMap;
        for (auto&& n : deck) {
            countMap[n]++;
        }

        // 仅有一个数则最大公约数是自己
        if (countMap.size() == 1) {
            return true;
        }

        // 两两求公约数
        int preNum = 0;
        for (auto&& n : countMap) {
            // 记录第一个数字
            if (preNum == 0) {
                preNum = n.second;
                continue;
            }

            // 逐个的求最大公约数
            preNum = gcd(preNum, n.second);
            if (preNum < 2) {
                break;
            }
        }

        return preNum < 2 ? false : true;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;

    param = {1, 2, 3, 4, 4, 3, 2, 1};
    REQUIRE(s.hasGroupsSizeX(param) == true);

    param = {1, 1, 1, 2, 2, 2, 3, 3};
    REQUIRE(s.hasGroupsSizeX(param) == false);

    param = {1};
    REQUIRE(s.hasGroupsSizeX(param) == false);

    param = {1, 1};
    REQUIRE(s.hasGroupsSizeX(param) == true);

    param = {1, 1, 2, 2, 2, 2};
    REQUIRE(s.hasGroupsSizeX(param) == true);
}
