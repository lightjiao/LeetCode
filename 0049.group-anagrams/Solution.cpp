/**
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
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
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // 排序, 记录map-vector的结果, append
        unordered_map<string, vector<string>> m;

        for (auto&& s : strs) {
            string ss(s);
            sort(ss.begin(), ss.end());
            m[ss].push_back(s);
        }

        vector<vector<string>> result;
        for (auto&& n : m) {
            result.push_back(n.second);
        }
        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<string>         param;
    vector<vector<string>> result;
    vector<vector<string>> expect;

    param  = {"eat", "tea", "tan", "ate", "nat", "bat"};
    result = s.groupAnagrams(param);
    expect = {{"ate", "eat", "tea"}, {"nat", "tan"}, {"bat"}};
    VV::print(result);
    REQUIRE(VV::equal(result, expect) == true);
}
