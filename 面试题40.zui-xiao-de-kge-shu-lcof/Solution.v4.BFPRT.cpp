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
     * 在一堆数中求其前 k 大或前 k 小的问题，简称 TOP-K 问题。而目前解决 TOP-K
     * 问题最有效的算法即是 BFPRT 算法，又称为中位数的中位数算法，该算法由
     * Blum、Floyd、Pratt、Rivest、Tarjan 提出，最坏时间复杂度为 O(n)。
     *
     * BFPRT 算法的做法:
     * 在快速排序的基础上，首先通过判断主元位置与k的大小使递归的规模变小，
     * 其次通过修改快速排序中主元的选取方法来降低快速排序在最坏情况下的时间复杂度。
     *
     * BFPRT 算法步骤如下：
     *
     *  1.选取主元；
     *      1.1. 将 n 个元素按顺序分为 ⌊n/5⌋ 个组，每组 5
     *          个元素，若有剩余，舍去；
     *      1.2. 对于这 ⌊n/5⌋ 个组中的每一组使用插入排序找到它们各自的中位数；
     *      1.3. 对于 1.2 中找到的所有中位数，调用 BFPRT
     *          算法求出它们的中位数，作为主元；
     *  2.以 1.3选取的主元为分界点，把小于主元的放在左边，大于主元的放在右边；
     *  3.判断主元的位置与 k 的大小，有选择的对左边或右边递归。
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        int pos = BFPRT(arr, 0, arr.size() - 1, k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }

private:
    int BFPRT(vector<int>& arr, int l, int r, int k)
    {
        if (k == 0) {
            return 0;
        }

        // 获取主元
        int pivotIdx     = getPivotIdx(arr, l, r);
        int partitionIdx = partition(arr, l, r, pivotIdx);

        int num = partitionIdx - l + 1;
        if (num == k) {
            return partitionIdx;
        }
        else if (num > k) {
            return BFPRT(arr, l, partitionIdx - 1, k);
        }
        else {
            return BFPRT(arr, num + 1, r, k - num);
        }
    }

    /**
     * 寻找中位数的中位数下标, 作为pivot
     */
    int getPivotIdx(vector<int>& nums, int l, int r)
    {
        if (r - l < 5) {
            return insertSort(nums, l, r);
        }

        // 每五个取中位数，并将中位数移动到数组首位
        int subRight = l - 1;
        for (int i = l; i + 4 <= r; i += 5) {
            int index = insertSort(nums, i, i + 4);
            swap(nums[++subRight], nums[index]);
            // subRight++;
        }

        return BFPRT(nums, l, subRight, ((subRight - l + 1) >> 1) + 1);
    }

    /**
     * 插入排序获得中位数
     */
    int insertSort(vector<int>& nums, int l, int r)
    {
        int temp, j;
        for (int i = l + 1; i <= r; i++) {
            temp = nums[i];

            j = i - 1;

            while (j >= l && nums[j] > temp) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = temp;
        }

        return ((r - l) >> 1) + l;
    }

    /**
     * 返回分界点下标的快排
     */
    int partition(vector<int>& nums, int l, int r, int pivotIdx)
    {
        // 将pivot移动至数组末端
        swap(nums[pivotIdx], nums[r]);

        int lessIdx = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] < nums[r]) {
                swap(nums[i], nums[lessIdx]);
                lessIdx++;
            }
        }
        swap(nums[r], nums[lessIdx]);

        return lessIdx;
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

    arr = {0, 0, 0, 2, 0, 5};
    REQUIRE_THAT(s.getLeastNumbers(arr, 0),
                 Catch::Matchers::UnorderedEquals(vector<int>({})));
}