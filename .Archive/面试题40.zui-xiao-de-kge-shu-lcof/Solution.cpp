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
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());
        return vector<int>(arr.begin(), arr.begin() + k);
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