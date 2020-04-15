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
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    /**
     * 以0为中心bfs
     */
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>  dist(m, vector<int>(n));
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        queue<pair<int, int>> q;
        // 将所有0 添加进初始队列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (0 == matrix[i][j]) {
                    q.emplace(i, j);
                    seen[i][j] = true;
                }
            }
        }

        // bfs
        while (false == q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];

                if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                    continue;
                }
                if (true == seen[ni][nj]) {
                    continue;
                }
                seen[ni][nj] = true;

                dist[ni][nj] = dist[i][j] + 1;
                q.emplace(ni, nj);
            }
        }

        return dist;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<vector<int>> param, result, expect;

    param = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    expect = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0},
    };
    REQUIRE(s.updateMatrix(param) == expect);

    param = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1},
    };
    expect = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 2, 1},
    };
    REQUIRE(s.updateMatrix(param) == expect);
};
