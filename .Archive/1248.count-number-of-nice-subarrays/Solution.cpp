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
     * 双指针
     */
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int p1 = 0, p2 = 0;
        int result = 0;

        int subArrayOddCount = 0;
        while (p2 < nums.size())
        {
            if (nums[p2] % 2 == 1)
            {
                subArrayOddCount++;
            }

            if (subArrayOddCount == k)
            {
                result += countK(p1, nums);
            }

            if (subArrayOddCount == k + 1)
            {
                while (nums[p1] % 2 == 0)
                {
                    p1++;
                }
                p1++;
                subArrayOddCount--;

                result += countK(p1, nums);
            }

            p2++;
        }

        return result;
    }

    inline int countK(int p1, vector<int>& nums)
    {
        int result = 0;
        // 重复的处理p1
        result++;
        int tempP1 = p1;
        while (nums[tempP1] % 2 == 0)
        {
            tempP1++;
            result++;
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;

    param = {1, 1, 2, 1, 1};
    REQUIRE(s.numberOfSubarrays(param, 3) == 2);

    param = {2, 4, 6};
    REQUIRE(s.numberOfSubarrays(param, 1) == 0);

    param = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    REQUIRE(s.numberOfSubarrays(param, 2) == 16);

    param = {3, 8, 0, 1, 8, 3, 0, 2, 2, 8, 8, 3, 1, 1};
    REQUIRE(s.numberOfSubarrays(param, 4) == 6);

    param = {91473, 45388, 24720, 35841, 29648, 77363, 86290,
             58032, 53752, 87188, 34428, 85343, 19801, 73201};
    REQUIRE(s.numberOfSubarrays(param, 4) == 6);
};
