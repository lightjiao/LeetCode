/**
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊
n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.majorityElement({3, 2, 3}) == 3);
    REQUIRE(s.majorityElement({2, 2, 1, 1, 1, 2, 2}) == 2);
    REQUIRE(s.majorityElement({1}) == 1);
}
