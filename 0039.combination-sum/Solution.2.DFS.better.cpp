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
     * !去掉重复结果：
     * !深度遍历的时候，只从candidates 的下标i 开始，而从i
     * !往下的深度遍历,只继续遍历[i..]的下标,不遍历[0..i)的下标,这样就能避免重复
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        // sum, candidates.index, path
        typedef tuple<int, int, vector<int>> Comb;

        stack<Comb> stk;
        for (int i = 0; i < candidates.size(); i++) {
            stk.push(Comb(candidates[i], i, {candidates[i]}));
        }

        vector<vector<int>> result;
        while (stk.empty() == false) {
            auto [sum, idx, list] = stk.top();
            stk.pop();

            if (sum > target || idx >= candidates.size()) {
                continue;
            }
            if (sum == target) {
                result.push_back(list);
                continue;
            }

            // 只遍历[i..]的数据，不遍历[0..i)的数据，避免结果重复
            for (int i = idx; i < candidates.size(); i++) {
                vector<int> newList(list);
                newList.push_back(candidates[i]);
                stk.emplace(Comb(sum + candidates[i], i, newList));
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
    expect = {{7}, {2, 2, 3}};
    REQUIRE(vectorOfVectorEqual(result, expect));

    nums   = {2, 3, 5};
    result = s.combinationSum(nums, 8);
    expect = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
    REQUIRE(vectorOfVectorEqual(result, expect));

    nums   = {1, 2};
    result = s.combinationSum(nums, 4);
    print2DVector(result);
    expect = {{1, 1, 1, 1}, {1, 1, 2}, {2, 2}};
    REQUIRE(vectorOfVectorEqual(result, expect));
}
