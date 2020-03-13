/**
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
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
    map<char, vector<string>> keyboard;

    Solution()
    {
        keyboard['2'] = {"a", "b", "c"};
        keyboard['3'] = {"d", "e", "f"};
        keyboard['4'] = {"g", "h", "i"};
        keyboard['5'] = {"j", "k", "l"};
        keyboard['6'] = {"m", "n", "o"};
        keyboard['7'] = {"p", "q", "r", "s"};
        keyboard['8'] = {"t", "u", "v"};
        keyboard['9'] = {"w", "x", "y", "z"};
    }

    /**
     * 暴力拼接的队列写法, 比较巧妙
     */
    vector<string> letterCombinations(string digits)
    {
        deque<string> ansQueue;
        if (digits.size() == 0) {
            return vector<string>({ansQueue.begin(), ansQueue.end()});
        }

        ansQueue.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            while (ansQueue.front().size() == i) {
                string prefix = ansQueue.front();
                ansQueue.pop_front();
                for (auto&& str : keyboard[digits[i]]) {
                    ansQueue.push_back(prefix + str);
                }
            }
        }

        return vector<string>({ansQueue.begin(), ansQueue.end()});
    }
};

void test(string digits, vector<string> expect)
{
    vector<string> result = (Solution()).letterCombinations(digits);
    sort(result.begin(), result.end());
    sort(expect.begin(), expect.end());
    REQUIRE(result == expect);
}

TEST_CASE("test")
{
    test("23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
    test("234",
         {"adg", "adh", "adi", "aeg", "aeh", "aei", "afg", "afh", "afi",
          "bdg", "bdh", "bdi", "beg", "beh", "bei", "bfg", "bfh", "bfi",
          "cdg", "cdh", "cdi", "ceg", "ceh", "cei", "cfg", "cfh", "cfi"});
}
