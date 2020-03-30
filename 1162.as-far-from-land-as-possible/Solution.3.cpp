/**
你现在手里有一份大小为 N x N
的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，
你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。

我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1,
y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。
 

示例 1：
输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释：
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。

示例 2：
输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释：
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 
提示：
1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1

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
     * 动态规划
     * dp[][]
     * dp[i][j] = min(dp[i-1][j-1]...dp[i+1][j+1]) + 1
     * 以每一个1为中心扩散出去计算dp
     * dp如果取到了更小的值则不再计算
     * 一直到将所有的1都遍历完成
     */
    int maxDistance(vector<vector<int>>& grid)
    {
        if (grid.size() == 0) {
            return 0;
        }

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                if (i + 1 < grid.size()) {
                    beforeDp(i + 1, j, grid, dp);
                }
                if (i - 1 >= 0) {
                    beforeDp(i - 1, j, grid, dp);
                }
                if (j + 1 < grid[i].size()) {
                    beforeDp(i, j + 1, grid, dp);
                }
                if (j - 1 >= 0) {
                    beforeDp(i, j - 1, grid, dp);
                }
            }
        }

        int result = -1;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }

    void beforeDp(int i, int j, vector<vector<int>>& grid,
                  vector<vector<int>>& dp)
    {
        if (grid[i][j] == 1) {
            return;
        }
        dp[i][j] = 1;
        dpDistance(i, j, grid, dp);
    }

    void dpDistance(int i, int j, vector<vector<int>>& grid,
                    vector<vector<int>>& dp)
    {
        if (i + 1 < grid.size() && grid[i + 1][j] == 0) {
            int newDp = dp[i][j] + 1;
            if (dp[i + 1][j] == -1) {
                dp[i + 1][j] = newDp;
                dpDistance(i + 1, j, grid, dp);
            }
            else if (newDp < dp[i + 1][j]) {
                dp[i + 1][j] = newDp;
                dpDistance(i + 1, j, grid, dp);
            }
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 0) {
            int newDp = dp[i][j] + 1;
            if (dp[i - 1][j] == -1) {
                dp[i - 1][j] = newDp;
                dpDistance(i - 1, j, grid, dp);
            }
            else if (newDp < dp[i - 1][j]) {
                dp[i - 1][j] = newDp;
                dpDistance(i - 1, j, grid, dp);
            }
        }
        if (j + 1 < grid[i].size() && grid[i][j + 1] == 0) {
            int newDp = dp[i][j] + 1;
            if (dp[i][j + 1] == -1) {
                dp[i][j + 1] = newDp;
                dpDistance(i, j + 1, grid, dp);
            }
            else if (newDp < dp[i][j + 1]) {
                dp[i][j + 1] = newDp;
                dpDistance(i, j + 1, grid, dp);
            }
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 0) {
            int newDp = dp[i][j] + 1;
            if (dp[i][j - 1] == -1) {
                dp[i][j - 1] = newDp;
                dpDistance(i, j - 1, grid, dp);
            }
            else if (newDp < dp[i][j - 1]) {
                dp[i][j - 1] = newDp;
                dpDistance(i, j - 1, grid, dp);
            }
        }
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<vector<int>> param;

    param = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    REQUIRE(s.maxDistance(param) == 2);

    param = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    REQUIRE(s.maxDistance(param) == 4);

    param = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    REQUIRE(s.maxDistance(param) == -1);

    param = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    REQUIRE(s.maxDistance(param) == -1);
}
