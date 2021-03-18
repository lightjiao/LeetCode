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
                if (grid[i][j] == 1) {
                    result = max(result, dfs(i, j, grid));
                }
            }
        }

        return result;
    }

    /**
     * ! 沉岛思想，将遍历过的1 置为0，减少空间的消耗
     * 并且用递归来实现深度遍历
     */
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        int result = 0;

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) {
            return result;
        }
        if (grid[i][j] == 0) {
            return result;
        }

        grid[i][j] = 0;
        result++;
        result += dfs(i + 1, j, grid);
        result += dfs(i - 1, j, grid);
        result += dfs(i, j + 1, grid);
        result += dfs(i, j - 1, grid);

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
