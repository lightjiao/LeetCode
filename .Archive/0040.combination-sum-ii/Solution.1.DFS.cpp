/**
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        // sum, candidates.index, path
        typedef tuple<int, int, vector<int>> Comb;

        stack<Comb> stk;
        for (int i = 0; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }

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
            for (int i = idx + 1; i < candidates.size(); i++) {
                if (i > idx + 1 && candidates[i] == candidates[i - 1]) {
                    continue;
                }

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

    nums   = {10, 1, 2, 7, 6, 1, 5};
    result = s.combinationSum2(nums, 8);
    VV::print(result);
    expect = {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}};
    REQUIRE(VV::equal(result, expect));

    nums   = {2, 5, 2, 1, 2};
    result = s.combinationSum2(nums, 5);
    expect = {{1, 2, 2}, {5}};
    REQUIRE(VV::equal(result, expect));
}
