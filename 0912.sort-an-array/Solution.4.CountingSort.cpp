/**
给你一个整数数组 nums，请你将该数组升序排列。

示例 1：
输入：nums = [5,2,3,1]
输出：[1,2,3,5]

示例 2：
输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 
提示：

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000
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
     * 计数排序
     * 计数排序是典型的空间换时间算法，开辟额外数据空间存储用索引号记录数组的值和数组值个数
     * 将数字计算出唯一顺序下标，并存放到下标的数组中，最后遍历整理数组的内容
     */
    vector<int> sortArray(vector<int>& nums)
    {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }

        int _min = *min_element(nums.begin(), nums.end());
        int _max = *max_element(nums.begin(), nums.end());

        vector<int> Counting(_max - _min + 1, 0);
        for (auto&& n : nums) {
            Counting[n - _min] += 1;
        }

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (Counting[j] == 0) {
                j++;
            }
            nums[i] = _min + j;
            Counting[j]--;
        }

        return nums;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> param;
    vector<int> expect;

    param  = {5, 2, 3, 1};
    expect = {1, 2, 3, 5};
    REQUIRE(s.sortArray(param) == expect);

    param  = {5, 1, 1, 2, 0, 0};
    expect = {0, 0, 1, 1, 2, 5};
    REQUIRE(s.sortArray(param) == expect);

    param  = {1, 1, 3, 3, 2, 2, 5, 5, 4, 4};
    expect = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    REQUIRE(s.sortArray(param) == expect);
}
