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
     * 动态规划
     */
    bool canJump(vector<int>& nums)
    {
        if (nums.size() == 0) { return true; }

        vector<bool> dp(nums.size(), false);
        dp[0] = true;

        for (int i = 1; i < nums.size(); i++) {
            //
            bool i_canJump = false;

            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == true && j + nums[j] >= i) {
                    i_canJump = true;
                    break;
                }
            }

            dp[i] = i_canJump;
        }

        return dp[nums.size() - 1];
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
