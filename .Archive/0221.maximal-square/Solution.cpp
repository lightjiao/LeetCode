/**
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:
输入:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
输出: 4
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../TreeNode.cpp"
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
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int result = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                result = max(result, calculateSquare(matrix, i, j));
            }
        }

        return result;
    }

    int calculateSquare(vector<vector<char>>& matrix, int i, int j)
    {
        int result = 0;
        while (checkBorder(matrix, i, j, result))
        {
            result++;
        }

        return result * result;
    }

    bool checkBorder(vector<vector<char>>& matrix, int i, int j, int border)
    {
        if (i + border >= matrix.size() || j + border >= matrix[i].size())
        {
            return false;
        }

        for (int m = border; m >= 0; m--)
        {
            if (matrix[i + border][j + m] == '0' ||
                matrix[i + m][j + border] == '0')
            {
                return false;
            }
        }

        return true;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<vector<char>> param;

    param = {
        {'1', '1'},
        {'1', '1'},
    };
    REQUIRE(s.maximalSquare(param) == 4);

    param = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    REQUIRE(s.maximalSquare(param) == 4);

    param = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    REQUIRE(s.maximalSquare(param) == 4);
}
