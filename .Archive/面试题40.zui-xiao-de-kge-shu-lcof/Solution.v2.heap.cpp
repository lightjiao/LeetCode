/**
输入整数数组 arr ，找出其中最小的 k
个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]


限制：

0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 利用堆(适用于频繁插入排序的完全二叉树)
     * 存储前k的数字，然后遍历arr，将比堆中小的数字都放入到堆中 空间复杂度 O(k)
     *
     * 时间复杂度 O(nlogk), 插入堆的时间复杂度是 logk,
     * 而最坏的情况，每个数都要插入堆，所以是 O(nlogk)
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        vector<int> result(k, 0);
        if (k == 0) {
            return result;
        }

        // Priority queues are a type of container adaptors, specifically
        // designed such that its first element is always the greatest of the
        // elements it contains, according to some strict weak ordering
        // criterion.
        priority_queue<int> q;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }

        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < q.top()) {
                q.pop();
                q.push(arr[i]);
            }
        }

        for (int i = 0; q.empty() == false; i++) {
            result[i] = q.top();
            q.pop();
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;

    vector<int> arr;

    arr = {3, 2, 1};
    REQUIRE_THAT(s.getLeastNumbers(arr, 2),
                 Catch::Matchers::UnorderedEquals(vector<int>({1, 2})));

    arr = {0, 1, 2, 1};
    REQUIRE_THAT(s.getLeastNumbers(arr, 1),
                 Catch::Matchers::UnorderedEquals(vector<int>({0})));
}