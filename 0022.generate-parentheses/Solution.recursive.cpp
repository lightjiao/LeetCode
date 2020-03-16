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
        stack<char> braceStack;
        recursive("", braceStack, n);

        return this->m_result;
    }

    vector<string> m_result;

    /**
     * ! 实际上这里并不需要一定用栈，用int 来表示左括号右括号的数量也可以达到相同的目的, 见v2
     */
    void recursive(string combination, stack<char> braceStack, int n)
    {
        // 记录结果
        if (combination.size() > 0 && n == 0 && braceStack.empty()) {
            this->m_result.push_back(combination);
        }
        else {
            if (braceStack.empty() && n > 0) {
                stack<char> newStack(braceStack);
                newStack.push('(');
                recursive(combination + "(", newStack, n - 1);
            }

            if (false == braceStack.empty() && braceStack.top() == '(') {
                if (n > 0) {
                    stack<char> newStack(braceStack);
                    newStack.push('(');
                    recursive(combination + "(", newStack, n - 1);
                }

                stack<char> newStack(braceStack);
                newStack.pop();
                recursive(combination + ")", newStack, n);
            }
            // every ')' is pop, this condition is not avaliable.
            // if (braceStack.top() == ')') {
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