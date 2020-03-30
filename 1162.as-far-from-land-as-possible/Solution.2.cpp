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
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    static constexpr int MAX_N = 100 + 5;

    struct Coordinate
    {
        int x, y, step;
    };

    int                 n, m;
    vector<vector<int>> a;

    bool vis[MAX_N][MAX_N];

    int findNearestLand(int x, int y)
    {
        memset(vis, 0, sizeof vis);
        queue<Coordinate> q;
        q.push({x, y, 0});
        vis[x][y] = 1;
        while (!q.empty()) {
            auto f = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1))
                    continue;
                if (!vis[nx][ny]) {
                    q.push({nx, ny, f.step + 1});
                    vis[nx][ny] = 1;
                    if (a[nx][ny])
                        return f.step + 1;
                }
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid)
    {
        this->n = grid.size();
        this->m = grid.at(0).size();
        a       = grid;
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!a[i][j]) {
                    ans = max(ans, findNearestLand(i, j));
                }
            }
        }

        

        return ans;
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
