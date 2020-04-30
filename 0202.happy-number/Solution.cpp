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
    bool isHappy(int n)
    {
        unordered_set<int> numSet = {n};
        while (n != 1)
        {
            int num = 0;
            while (n > 0)
            {
                int y = n % 10;
                n     = n / 10;
                num   = num + y * y;
            }

            n = num;
            if (numSet.count(n) > 0)
            {
                return false;
            }
            numSet.emplace(n);
        }

        return true;
    }
};

TEST_CASE("test")
{
    Solution s;

    REQUIRE(s.isHappy(19) == true);
    REQUIRE(s.isHappy(3) == false);
};
