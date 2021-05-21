#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file

#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 给你 n 个非负整数
a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)。在坐标内画 n 条垂直线，垂直线
i 的两个端点分别为 (i, ai) 和 (i, 0)
 * 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。

n = height.length
2 <= n <= 3 * 104
0 <= height[i] <= 3 * 104

 */

class Program
{
public:
    int Invoke(vector<int>& height)
    {
        return 0;
    }

private:
};

TEST_CASE("test")
{
    Program s;

    /**
     * 输入：[1,8,6,2,5,4,8,3,7]
    输出：49
    解释：图中垂直线代表输入数组
    [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

    height = [1,1]
    输出：1

    输入：height = [4,3,2,1,4]
    输出：16

    输入：height = [1,2,1]
    输出：2
     */

    REQUIRE(s.Invoke({1, 8, 6, 2, 5, 4, 8, 3, 7}) == 49);
    // REQUIRE(s.lengthOfLongestSubstring("abcabcbb") == 3);
    // REQUIRE(s.lengthOfLongestSubstring("pwwkew") == 3);
}