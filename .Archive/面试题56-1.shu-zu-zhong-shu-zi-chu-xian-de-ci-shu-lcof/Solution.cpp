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
     * 利用二进制的位运算得出不重复的数据
     * XOR (Exclusive Or)
     * This operation is performed between two bits (a and b). The result is 1
     * if either one of the two bits is 1, but not in the case that both are.
     * There for, if neither or both of them are equal to 1 the result is 0.
     *
     * XOR (^)
     * a	b	a^b
     * 0	0	0
     * 0	1	1
     * 1	0	1
     * 1	1	0
     */
    vector<int> singleNumbers(vector<int>& nums)
    {
        int ret = 0;
        for (int n : nums)
            ret ^= n;
        int div = 1;
        while ((div & ret) == 0)
            div <<= 1;
        int a = 0, b = 0;
        for (int n : nums)
            if (div & n)
                a ^= n;
            else
                b ^= n;
        return vector<int>{a, b};
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> param, result;

    param  = {4, 1, 4, 6};
    result = s.singleNumbers(param);
    sort(result.begin(), result.end());
    REQUIRE(result == vector<int>{1, 6});

    param  = {1, 2, 10, 4, 1, 4, 3, 3};
    result = s.singleNumbers(param);
    sort(result.begin(), result.end());
    REQUIRE(result == vector<int>{2, 10});
};
