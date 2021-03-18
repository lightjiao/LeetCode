/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

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
     * 入栈就好啦
     */
    bool isValid(string s)
    {
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        stack<char> st;
        for (auto&& c : s) {
            if (st.empty()) {
                st.push(c);
                continue;
            }

            if (m.find(c) == m.end()) {
                st.push(c);
                continue;
            }

            if (m[c] == st.top()) {
                st.pop();
            }
            else {
                return false;
            }
        }

        return st.empty() ? true : false;
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.isValid("()") == true);
    REQUIRE(s.isValid("()[]{}") == true);
    REQUIRE(s.isValid("(]") == false);
    REQUIRE(s.isValid("([)]") == false);
    REQUIRE(s.isValid("{[]}") == true);
    REQUIRE(s.isValid("((){})") == true);
}
