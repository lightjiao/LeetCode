/**
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
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
    vector<string> generateParenthesis(int n)
    {
        recursive("", n, 0, 0);

        return this->m_result;
    }

    vector<string> m_result;

    /**
     * ! 实际上这里并不需要一定用栈，用int
     * ! 来表示左括号右括号的数量也可以达到相同的目的
     */
    void recursive(string combination, int n, int open, int close)
    {
        // 记录结果
        if (combination.size() > 0 && n == 0 && open == close) {
            this->m_result.push_back(combination);
        }
        else {
            if (open == close && n > 0) {
                recursive(combination + "(", n - 1, open + 1, close);
            }

            if (open > close) {
                if (n > 0) {
                    recursive(combination + "(", n - 1, open + 1, close);
                }

                recursive(combination + ")", n, open, close + 1);
            }
        }

        return;
    }
};

void test(int n, vector<string> expect);
TEST_CASE("test")
{
    test(3, {"((()))", "(()())", "(())()", "()(())", "()()()"});
}

void test(int n, vector<string> expect)
{
    vector<string> result = (Solution()).generateParenthesis(n);
    sort(expect.begin(), expect.end());
    sort(result.begin(), result.end());

    REQUIRE(result == expect);
}