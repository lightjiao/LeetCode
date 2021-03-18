/**
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
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
     * 直接计算下标做计算
     */
    void rotate(vector<vector<int>>& matrix)
    {
        int old_temp, new_temp;
        int old_i, old_j, new_i, new_j;

        int maxIdx = matrix.size() - 1;

        // 特殊处理一下奇数矩阵的边界
        int iRang = maxIdx / 2;
        if (matrix.size() % 2 == 1) {
            iRang--;
        }

        // 只处理1/4的矩阵
        for (int i = 0; i <= iRang; i++) {
            for (int j = 0; j <= maxIdx / 2; j++) {
                old_i    = i;
                old_j    = j;
                old_temp = matrix[old_i][old_j];

                int loop = 4;
                while (loop--) {
                    // 计算新的下标
                    new_i = old_j;
                    new_j = maxIdx - old_i;

                    // 将值移动到新的下标
                    new_temp             = matrix[new_i][new_j];
                    matrix[new_i][new_j] = old_temp;

                    // 将新的下标变成旧的下标
                    old_i    = new_i;
                    old_j    = new_j;
                    old_temp = new_temp;
                }
            }
        }
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<vector<int>> param;
    vector<vector<int>> expect;

    param = {{1, 2}, {3, 4}};
    s.rotate(param);
    expect = {{3, 1}, {4, 2}};
    REQUIRE(param == expect);

    param = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    s.rotate(param);
    expect = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    REQUIRE(param == expect);

    param = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(param);
    expect = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    REQUIRE(param == expect);
}
