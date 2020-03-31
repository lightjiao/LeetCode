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
     * 快排
     */
    vector<int> sortArray(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r)
    {
        // 选一个数字
        // 比数字大的，移动到右边
        // 比数字小的，移动到左边
        // 递归的调用左右
        if (l >= r) {
            return;
        }

        int pivot = nums[r];

        int pos = l;
        while (pos < r && nums[pos] <= pivot) {
            pos++;
        }

        for (int i = pos; i < r; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }
        swap(nums[pos], nums[r]);

        quickSort(nums, l, pos - 1);
        quickSort(nums, pos + 1, r);
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
