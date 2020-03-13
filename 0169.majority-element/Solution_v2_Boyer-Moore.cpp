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
    /**
     * Boyer-Moore 投票算法
     * 思路:
     *
     * 如果我们把众数记为 +1+1，把其他数记为 -1−1，将它们全部加起来，显然和大于
     * 0，从结果本身我们可以看出众数比其他数多。
     */
    int majorityElement(vector<int> nums)
    {
        int candidate;
        int count = 0;
        for (auto&& n : nums) {
            if (count == 0) {
                candidate = n;
            }
            if (n == candidate) {
                count++;
            }
            else {
                count--;
            }
        }

        return candidate;
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.majorityElement({3, 2, 3}) == 3);
    REQUIRE(s.majorityElement({2, 2, 1, 1, 1, 2, 2}) == 2);
    REQUIRE(s.majorityElement({1}) == 1);
}
