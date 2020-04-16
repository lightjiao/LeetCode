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
    /*
     * 排序后暴力梭哈总是能做出来的
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        auto f = [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), f);

        vector<vector<int>> result;
        unordered_set<int>  merged;

        for (int i = 0; i < intervals.size(); i++) {
            if (merged.find(i) != merged.end()) { continue; }

            auto interval = intervals[i];

            for (int j = i + 1; j < intervals.size(); j++) {
                if (merged.find(j) != merged.end()) { continue; }

                // 不重叠取反就是重叠
                if (interval[1] < intervals[j][0] ||
                    interval[0] > intervals[j][1]) {
                    continue;
                }

                merged.emplace(j);

                interval[0] = min(interval[0], intervals[j][0]);
                interval[1] = max(interval[1], intervals[j][1]);
            }

            result.push_back(interval);
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<vector<int>> param, result, expect;

    param  = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    expect = {{1, 6}, {8, 10}, {15, 18}};
    result = s.merge(param);
    REQUIRE(VV::equal(result, expect) == true);

    param  = {{1, 4}, {4, 5}};
    expect = {{1, 5}};
    result = s.merge(param);
    REQUIRE(VV::equal(result, expect) == true);

    param  = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    expect = {{1, 10}};
    result = s.merge(param);
    VV::print(result);
    REQUIRE(VV::equal(result, expect) == true);

    param  = {{4, 5}, {1, 4}, {0, 1}};
    expect = {{0, 5}};
    result = s.merge(param);
    REQUIRE(VV::equal(result, expect) == true);

    // A与B重叠， B与C重叠，但A与C不重叠，结果会是怎样的? 题目没说
    // param  = {{1, 4}, {3, 6}, {5, 8}};
    // expect = {{1, 6}, {3, 8}};
    // result = s.merge(param);
    // VV::print(result);
    // REQUIRE(VV::equal(result, expect) == true);
};
