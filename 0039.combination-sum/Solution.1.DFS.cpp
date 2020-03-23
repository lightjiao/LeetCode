/**
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../Utility.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 深度优先遍历
     * ! 这里需要重点注意的是如何去掉重复的结果
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        // 记录哪些数据已经被遍历过
        unordered_map<int, unordered_set<int>> combinationMap;

        typedef pair<int, vector<int>> Comb;

        stack<Comb> stk;
        for (auto&& n : candidates) {
            stk.push(Comb(n, {n}));
        }

        vector<vector<int>> result;
        while (stk.empty() == false) {
            auto [sum, list] = stk.top();
            stk.pop();

            if (sum > target) {
                continue;
            }
            if (sum == target) {
                result.push_back(list);
            }

            // 找出没有遍历过的点，入栈
            for (auto&& n : candidates) {
                if (combinationMap[sum].count(n) == 0) {
                    combinationMap[sum].emplace(n);

                    vector<int> newList(list);
                    newList.push_back(n);
                    stk.emplace(Comb(sum + n, newList));
                }
            }
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution            s;
    vector<int>         nums;
    vector<vector<int>> result;
    vector<vector<int>> expect;

    nums   = {2, 3, 6, 7};
    result = s.combinationSum(nums, 7);
    print2DVector(result);
    expect = {{7}, {2, 2, 3}};
    REQUIRE(vectorOfVectorEqual(result, expect));

    nums   = {2, 3, 5};
    result = s.combinationSum(nums, 8);
    expect = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    REQUIRE(vectorOfVectorEqual(result, expect));
}
