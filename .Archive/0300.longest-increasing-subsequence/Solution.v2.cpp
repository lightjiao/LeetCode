/**
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
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
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 动态规划 + 二分
     * 新建数组 cell，用于保存最长上升子序列。
     * 对原序列进行遍历，将每位元素二分插入 cell 中。
     *      如果 cell 中元素都比它小，将它插到最后
     *      否则，用它覆盖掉比它大的元素中最小的那个。
     * 总之，思想就是让 cell 中存储比较小的元素。这样，cell
     * 未必是真实的最长上升子序列，但长度是对的。
     */
    int lengthOfLIS(vector<int> nums)
    {
        vector<int> cell;
        for (auto&& n : nums) {
            int pos = getInsertPos(cell, n);
            if (pos == -1) {
                cell.push_back(n);
            }
            else {
                cell[pos] = n;
            }
        }

        return cell.size();
    }

    int getInsertPos(vector<int>& cell, int num)
    {
        if (cell.size() == 0 || cell[cell.size() - 1] < num) {
            return -1;
        }

        int L = 0, R = cell.size() - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if (cell[mid] < num) {
                L = mid + 1;
            }
            else {
                R = mid;
            }
        }

        return L;
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    REQUIRE(s.lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18, 19}) == 5);
    REQUIRE(s.lengthOfLIS({}) == 0);
}
