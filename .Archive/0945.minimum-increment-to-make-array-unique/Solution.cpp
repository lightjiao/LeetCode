/**
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

返回使 A 中的每个值都是唯一的最少操作次数。

示例 1:

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
示例 2:

输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
提示：

0 <= A.length <= 40000
0 <= A[i] < 40000
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 暴力枚举，复杂度为 O(n^2), 太慢了
     */
    int minIncrementForUnique(vector<int>& A)
    {
        sort(A.begin(), A.end());
        int move = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] == A[i - 1]) {
                int beforeMove = A[i];
                A[i]++;
                move++;
                resort(A, i);

                if (i < A.size() - 1 && A[i] == beforeMove) {
                    i--;
                }
            }
        }

        return move;
    }

    void resort(vector<int>& A, int pos)
    {
        int swapPos = pos + 1;
        for (; swapPos < A.size(); swapPos++) {
            if (A[swapPos] >= A[pos]) {
                break;
            }
        }
        swapPos--;
        swap(A[pos], A[swapPos]);
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> param;

    param = {1, 2, 2};
    REQUIRE(s.minIncrementForUnique(param) == 1);

    param = {3, 2, 1, 2, 1, 7};
    REQUIRE(s.minIncrementForUnique(param) == 6);

    param = {2, 2, 2, 1};
    REQUIRE(s.minIncrementForUnique(param) == 3);
}