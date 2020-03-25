/**
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
请你返回最终形体的表面积。

示例 1：
输入：[[2]]
输出：10

示例 2：
输入：[[1,2],[3,4]]
输出：34

示例 3：
输入：[[1,0],[0,2]]
输出：16

示例 4：
输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32

示例 5：
输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46
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
     * 直接就这么算
     */
    int surfaceArea(vector<vector<int>>& grid)
    {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > 0) {
                    result += 2;
                }

                // 查看周边grid的高度
                // left
                int left = i > 0 ? grid[i][j] - grid[i - 1][j] : grid[i][j];
                if (left > 0) {
                    result += left;
                }

                // right
                int right = i < grid.size() - 1 ? grid[i][j] - grid[i + 1][j] :
                                                  grid[i][j];
                if (right > 0) {
                    result += right;
                }

                // top
                int top = j < grid[i].size() - 1 ? grid[i][j] - grid[i][j + 1] :
                                                   grid[i][j];
                if (top > 0) {
                    result += top;
                }

                int buttom = j > 0 ? grid[i][j] - grid[i][j - 1] : grid[i][j];
                if (buttom > 0) {
                    result += buttom;
                }
            }
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<vector<int>> grid;

    grid = {{2}};
    REQUIRE(s.surfaceArea(grid) == 10);

    grid = {{1, 2}, {3, 4}};
    REQUIRE(s.surfaceArea(grid) == 34);

    grid = {{1, 0}, {0, 2}};
    REQUIRE(s.surfaceArea(grid) == 16);

    grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    REQUIRE(s.surfaceArea(grid) == 32);

    grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
    REQUIRE(s.surfaceArea(grid) == 46);
}
