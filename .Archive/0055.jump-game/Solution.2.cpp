#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
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
     * 贪心策略其实更好
     */
    bool canJump(vector<int>& nums)
    {
        /**
         * k 代表着第 i 个nums能够跳到的最远距离
         * 逐个遍历 i ，并不断的更新所有的 i 能够达到的最远距离
         * 如果出现 i 已经比之前所有的 i 跳的距离还要远，说明这个 i 是不可达的
         */ 
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }

        return true;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;

    param = {2, 3, 1, 1, 4};
    REQUIRE(s.canJump(param) == true);

    param = {3, 2, 1, 0, 4};
    REQUIRE(s.canJump(param) == false);
};
