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
    /**
     * 暴力梭哈，但显然时间复杂度太高
     */
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> result(matrix.size(),
                                   vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                result[i][j] = findNeareastZero(i, j, matrix);
            }
        }

        return result;
    }

    vector<pair<int, int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int findNeareastZero(int i, int j, vector<vector<int>>& matrix)
    {
        vector<vector<bool>> theWay(matrix.size(),
                                    vector<bool>(matrix[0].size(), false));

        queue<pair<int, int>> q;
        q.emplace(i, j);

        while (q.empty() == false) {
            int x = q.front().first;
            int y = q.front().second;
            // auto [x, y] = q.front();
            q.pop();

            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[x].size()) {
                continue;
            }

            if (true == theWay[x][y]) {
                continue;
            }

            theWay[x][y] = true;

            if (matrix[x][y] == 0) {
                return abs(x - i) + abs(y - j);
            }
            else {
                for (auto&& n : move) {
                    q.emplace(x + n.first, y + n.second);
                }
            }
        }

        return 0;
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
