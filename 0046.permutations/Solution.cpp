/**
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
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
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;

        typedef pair<vector<int>, unordered_set<int>> PII;

        stack<PII> stk;
        for (auto&& n : nums) {
            stk.push(PII({n}, {n}));
        }
        while (stk.empty() == false) {
            auto v = stk.top();
            stk.pop();

            if (v.first.size() == nums.size()) {
                // result.push_back(vector<int>(v.begin(), v.end()));
                result.push_back(v.first);
                continue;
            }

            for (auto&& n : nums) {
                if (v.second.count(n) == 0) {
                    auto vv(v);
                    vv.first.push_back(n);
                    vv.second.emplace(n);
                    stk.push(vv);
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

    nums   = {1, 2, 3};
    result = s.permute(nums);
    VV::print(result);
    expect = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    REQUIRE(VV::same(result, expect) == true);

    nums   = {0, -1, 1};
    result = s.permute(nums);
    VV::print(result);
    expect = {{0, -1, 1}, {0, 1, -1}, {-1, 0, 1},
              {-1, 1, 0}, {1, 0, -1}, {1, -1, 0}};
    REQUIRE(VV::same(expect, result) == true);
}
