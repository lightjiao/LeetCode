/**
 * 矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2,
y2) 是右上角的坐标。

如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠。

给出两个矩形，判断它们是否重叠并返回结果。

 

示例 1：

输入：rec1 = [0,0,2,2], rec2 = [1,1,3,3]
输出：true
示例 2：

输入：rec1 = [0,0,1,1], rec2 = [1,0,2,1]
输出：false
 

提示：

两个矩形 rec1 和 rec2 都以含有四个整数的列表的形式给出。
矩形中的所有坐标都处于 -10^9 和 10^9 之间。
x 轴默认指向右，y 轴默认指向上。
你可以仅考虑矩形是正放的情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-overlap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2)
    {
        // rec2 分别在 rec1 的上下左右的情况，再取[非]
        return !((rec1[3] <= rec2[1]) ||  // top
                 (rec1[1] >= rec2[3]) ||  // bottom
                 (rec1[0] >= rec2[2]) ||  // left
                 (rec1[2] <= rec2[0]));   // right
    }
};

TEST_CASE("test")
{
    Solution    s;
    vector<int> a;
    vector<int> b;

    a = {0, 0, 2, 2};
    b = {1, 1, 3, 3};
    REQUIRE(s.isRectangleOverlap(a, b) == true);

    a = {0, 0, 1, 1};
    b = {1, 0, 2, 1};
    REQUIRE(s.isRectangleOverlap(a, b) == false);

    a = {5, 15, 8, 18};
    b = {0, 3, 7, 9};
    REQUIRE(s.isRectangleOverlap(a, b) == false);

    a = {11, 12, 13, 13};
    b = {17, 1, 17, 19};
    REQUIRE(s.isRectangleOverlap(a, b) == false);

    a = {-836959955, -724514313, 368220652, -449465289};
    b = {-703416829, -64916327, 713807924, 838108468};
    REQUIRE(s.isRectangleOverlap(a, b) == false);
}
