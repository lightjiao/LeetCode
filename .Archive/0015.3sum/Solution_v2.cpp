/**
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include "../catch.hpp"
#include "limits.h"

using namespace std;

class Solution
{
public:
    /**
     * 排序 + 双指针
     */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 因为排序，所以之后的数字加起来不可能=0
            if (nums[i] > 0) {
                break;
            }
            // 重复数字不计算
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left  = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[left] + nums[i] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[left], nums[i], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if (sum < 0) {
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                }
                else {
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    right--;
                }
            }
        }

        return result;
    }
};

bool unittest(vector<int> nums, vector<vector<int>> expect);

TEST_CASE("test")
{
    Solution s;
    // REQUIRE(unittest({-1, 0, 1, 2, -1, -4}, {{-1, 0, 1}, {-1, -1, 2}}) == true);
    // REQUIRE(unittest({0, 0, 0, 0}, {{0, 0, 0}}) == true);
    // REQUIRE(unittest({-1, 0, 1, 0}, {{-1, 0, 1}}) == true);
    REQUIRE(unittest({1, -1, -1, 0}, {{-1, 0, 1}}) == true);
}

bool unittest(vector<int> nums, vector<vector<int>> expect)
{
    Solution            s;
    vector<vector<int>> result = s.threeSum(nums);

    if (result.size() != expect.size()) {
        cout << "size is not equal" << endl;
        for (auto&& n : result) {
            for (auto&& m : n) {
                cout << m << " ";
            }
            cout << endl;
        }

        return false;
    }

    // sort result element
    for (auto&& n : expect) {
        sort(n.begin(), n.end());
    }

    // sort expect element
    for (auto&& n : result) {
        cout << endl;
        sort(n.begin(), n.end());
    }

    // compare
    for (auto&& n : result) {
        bool equalFlag = false;
        for (auto&& m : expect) {
            if (n == m) {
                equalFlag = true;
                break;
            }
        }
        if (equalFlag == false) {
            return false;
        }
    }
    return true;
}
