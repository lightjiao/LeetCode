/**
 * DP 算法解决正则匹配
 * 
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * 自底向上的DP算法
     */
    bool isMatch(string text, string pattern)
    {
        vector<vector<int>> dp(text.size() + 1, vector<int>(pattern.size() + 1));
        dp[text.size()][pattern.size()] = true;

        for (int i = text.size(); i >= 0; i--)
        {
            for (int j = pattern.size() - 1; j >= 0; j--)
            {
                bool firstMatch = (i < text.size() &&
                                   (pattern[j] == text[i] || pattern[j] == '.'));

                if (j + 1 < pattern.size() && pattern[j + 1] == '*')
                {
                    // * 逻辑运算符 && 在 || 之上 https://zh.cppreference.com/w/cpp/language/operator_precedence
                    // dp[i][j] = dp[i][j + 2] || firstMatch && dp[i + 1][j];
                    dp[i][j] = (firstMatch && dp[i + 1][j]) || dp[i][j + 2];
                }
                else
                {
                    dp[i][j] = firstMatch && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};