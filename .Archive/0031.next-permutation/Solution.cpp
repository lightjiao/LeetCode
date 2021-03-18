/**
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
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
     * 从后往前，找到第一个降序的数字，比如 132中，2->3->1，1是第一个降序的数字
     * 将降序之前的数字中最小的，与降序的数字交换，再将之后的数字按从小到大排序即可
     */
    void nextPermutation(vector<int>& nums)
    {
        // 找出降序的位置pos
        int orderIndex = -1;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                orderIndex = i - 1;
                break;
            }
        }

        // 找到比orderIndex之后比nums[orderIndex]大的最小的数字
        int minNumIdx = -1;
        for (int i = orderIndex + 1; i < nums.size(); i++) {
            // orderIndex=-1时，找到不到比nums[orderIndex]还要大的数字
            if (orderIndex >= 0 && nums[i] <= nums[orderIndex]) {
                continue;
            }

            if (minNumIdx == -1) {
                minNumIdx = i;
            }
            else if (nums[i] < nums[minNumIdx]) {
                minNumIdx = i;
            }
        }

        // -1 转换为0
        orderIndex = (orderIndex == -1) ? 0 : orderIndex;

        // 交换位置
        swap(nums[minNumIdx], nums[orderIndex]);
        // 对orderIndex之后的数字排序
        sort(nums.begin() + orderIndex + 1, nums.end());

        return;
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> nums;
    vector<int> expect;

    nums   = {2, 3, 1};
    expect = {3, 1, 2};
    s.nextPermutation(nums);
    REQUIRE(nums == expect);

    nums   = {1, 2, 3};
    expect = {1, 3, 2};
    s.nextPermutation(nums);
    REQUIRE(nums == expect);

    nums   = {3, 2, 1};
    expect = {1, 2, 3};
    s.nextPermutation(nums);
    REQUIRE(nums == expect);

    nums   = {1, 1, 5};
    expect = {1, 5, 1};
    s.nextPermutation(nums);
    REQUIRE(nums == expect);
}