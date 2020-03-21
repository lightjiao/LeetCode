/**
有两个容量分别为 x升 和 y升
的水壶以及无限多的水。请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？

如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

你允许：

装满任意一个水壶
清空任意一个水壶
从一个水壶向另外一个水壶倒水，直到装满或者倒空
示例 1: (From the famous "Die Hard" example)

输入: x = 3, y = 5, z = 4
输出: True
示例 2:

输入: x = 2, y = 6, z = 5
输出: False
 */
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * 深度优先遍历
     * 首先对题目进行建模。观察题目可知，在任意一个时刻，此问题的状态可以由两个数字决定：X
     * 壶中的水量，以及 Y 壶中的水量。
     *
     * 在任意一个时刻，我们可以且仅可以采取以下几种操作：
     *      把 X 壶的水灌进 Y 壶，直至灌满或倒空；
     *      把 Y 壶的水灌进 X 壶，直至灌满或倒空；
     *      把 X 壶灌满；
     *      把 Y 壶灌满；
     *      把 X 壶倒空；
     *      把 Y 壶倒空。
     *
     * 因此，本题可以使用深度优先搜索来解决。搜索中的每一步以 remain_x,
     * remain_y 作为状态，即表示 X 壶和 Y
     * 壶中的水量。在每一步搜索时，我们会依次尝试所有的操作，递归地搜索下去。这可能会导致我们陷入无止境的递归，
     * 因此我们还需要使用一个哈希结合（HashSet）存储所有已经搜索过的
     * remain_x, remain_y 状态，保证每个状态至多只被搜索一次。
     **/
    bool canMeasureWater(int x, int y, int z)
    {
        using PII = pair<int, int>;

        map<int, map<int, bool>> xyMap;

        // 存储到 unorder_set中得hash函数
        auto hash_function = [](const PII& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);

        stack<PII> dfsStack;
        dfsStack.emplace(x, y);

        while (dfsStack.empty() == false) {
            if (seen.count(dfsStack.top())) {
                dfsStack.pop();
                continue;
            }
            seen.emplace(dfsStack.top());

            auto [remainX, remainY] = dfsStack.top();
            dfsStack.pop();

            if (remainX == z || remainY == z || remainX + remainY == z) {
                return true;
            }

            // 把X灌满
            dfsStack.emplace(x, remainY);
            // 把Y灌满
            dfsStack.emplace(remainX, y);
            // 把X倒空
            dfsStack.emplace(0, remainY);
            // 把Y倒空
            dfsStack.emplace(remainX, 0);
            // 把X倒入Y, 直到灌满或者倒空
            dfsStack.emplace(remainX - min(remainX, y - remainY),
                             remainY + min(remainX, y - remainY));
            // 把Y倒入X, 直到灌满或者倒空
            dfsStack.emplace(remainX + min(remainY, x - remainX),
                             remainY - min(remainY, x - remainX));
        }

        return false;
    }
};

TEST_CASE("test")
{
    REQUIRE((Solution()).canMeasureWater(3, 5, 4) == true);
    REQUIRE((Solution()).canMeasureWater(2, 6, 5) == false);
    REQUIRE((Solution()).canMeasureWater(1, 2, 3) == true);
    REQUIRE((Solution()).canMeasureWater(22003, 31237, 1) == true);
    REQUIRE((Solution()).canMeasureWater(104693, 104701, 324244) == false);
}