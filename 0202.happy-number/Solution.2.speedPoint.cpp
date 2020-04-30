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
     * 快慢指针, 所有循环检测的实现都可以用快慢指针来实现
     */
    bool isHappy(int n)
    {
        int quick = n, slow = n;

        while (true)
        {
            quick = getNext(getNext(quick));
            slow  = getNext(slow);

            if (quick == 1)
            {
                return true;
            }

            if (quick == slow)
            {
                return false;
            }
        }
    }

    int getNext(int n)
    {
        int num = 0;
        while (n > 0)
        {
            int y = n % 10;
            n     = n / 10;
            num   = num + y * y;
        }
        return num;
    }
};

TEST_CASE("test")
{
    Solution s;

    REQUIRE(s.isHappy(19) == true);
    REQUIRE(s.isHappy(3) == false);
    REQUIRE(s.isHappy(1) == true);
};
