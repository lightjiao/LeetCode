/**
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向
(水平或垂直) 的 1 (代表土地)
构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 广度遍历或者深度遍历
     */
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        if (grid.size() == 0) {
            return 0;
        }

        vector<vector<bool>> alreadyChecked(
            grid.size(), vector<bool>(grid[0].size(), false));

        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                result = max(result, dfs(i, j, grid, alreadyChecked));
            }
        }

        return result;
    }

    /**
     * 深度遍历需要出栈入栈操作
     */
    int dfs(int                   i,
            int                   j,
            vector<vector<int>>&  grid,
            vector<vector<bool>>& alreadyChecked)
    {
        int result = 0;
        if (grid[i][j] == 0 || alreadyChecked[i][j] == true) {
            return result;
        }

        stack<vector<int>> s;
        s.push({i, j});
        while (s.empty() == false) {
            vector<int> pos = s.top();
            s.pop();
            i = pos[0];
            j = pos[1];

            // 检查是否计算值
            if (alreadyChecked[i][j] || grid[i][j] == 0) {
                continue;
            }
            result++;
            alreadyChecked[i][j] = true;

            // 将有效得位置入栈
            if (i + 1 < grid.size()) {
                s.push({i + 1, j});
            }
            if (i - 1 >= 0) {
                s.push({i - 1, j});
            }
            if (j + 1 < grid[i].size()) {
                s.push({i, j + 1});
            }
            if (j - 1 >= 0) {
                s.push({i, j - 1});
            }
        }

        return result;
    }
};

TEST_CASE("test")
{
    vector<vector<int>> island_1 = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                    {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    vector<vector<int>> island_2 = {{0, 0, 0, 0, 0, 0, 0, 0}};

    vector<vector<int>> island_3 = {
        {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};

    Solution s;
    REQUIRE(s.maxAreaOfIsland(island_2) == 0);
    REQUIRE(s.maxAreaOfIsland(island_3) == 4);
    REQUIRE(s.maxAreaOfIsland(island_1) == 6);
}
