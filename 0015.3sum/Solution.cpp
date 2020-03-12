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
     * 暴力遍历枚举实现, 超出时间限制
     */
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        map<int, bool> firstIsDone;

        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            // 因为排序，所以之后的数字加起来不可能=0
            if (nums[i] > 0) {
                break;
            }

            if (firstIsDone.find(nums[i]) != firstIsDone.end()) {
                continue;
            }
            firstIsDone.insert(pair<int, bool>(nums[i], true));

            map<int, bool> secondIsDone;

            for (int j = i + 1; j < nums.size(); j++) {
                if (secondIsDone.find(nums[j]) != secondIsDone.end()) {
                    continue;
                }
                secondIsDone.insert(pair<int, bool>(nums[j], true));

                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        break;
                    }
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
    REQUIRE(unittest({-1, 0, 1, 2, -1, -4}, {{-1, 0, 1}, {-1, -1, 2}}) == true);
    REQUIRE(unittest({0, 0, 0, 0}, {{0, 0, 0}}) == true);
    REQUIRE(unittest({-1, 0, 1, 0}, {{-1, 0, 1}}) == true);
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
