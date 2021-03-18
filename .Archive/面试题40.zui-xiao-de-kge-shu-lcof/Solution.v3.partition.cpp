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
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * g++ -std=c++11 -O -g -fsanitize=address 编译后执行可以看segment falt信息
     * 基于快排
     * 原始的快排是将数组划分成两部分，小于等于分界值pivot的元素都会放在数组左边，其他的元素都会放在数组右边，然后返回下标。
     * 与快速排序不同的是，快速排序会递归的处理划分的两边，而这里我们只处理一边
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        srand((unsigned)time(NULL));

        randomizedSelected(arr, 0, (int)arr.size() - 1, k);

        return vector<int>(arr.begin(), arr.begin() + k);
    }

private:
    void randomizedSelected(vector<int>& nums, int l, int r, int k)
    {
        if (r <= l) {
            return;
        }

        // 获取random排序结果以及pivot的pos
        int pos = randomizedPartition(nums, l, r);
        int num = pos - l + 1;
        if (num == k) {
            return;
        }
        else if (num < k) {
            return randomizedSelected(nums, pos + 1, r, k - num);
        }
        else {
            return randomizedSelected(nums, l, pos - 1, k);
        }
    }

    int randomizedPartition(vector<int>& nums, int l, int r)
    {
        // 生成随机下标，并将下标交换到数组的最后位置，再进行快排
        int randomIdx = (rand() % (r - l + 1)) + l;
        swap(nums[r], nums[randomIdx]);
        return partition(nums, l, r);
    }

    int partition(vector<int>& nums, int l, int r)
    {
        int pivot = nums[r];
        int i     = l - 1;

        for (int j = l; j < r; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);

        return i + 1;
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

    arr = {0, 0, 1, 3, 4, 5, 0, 7, 6, 7};
    REQUIRE_THAT(s.getLeastNumbers(arr, 9),
                 Catch::Matchers::UnorderedEquals(
                     vector<int>({0, 0, 0, 1, 3, 4, 5, 6, 7})));
}