#include <string>
#include <iostream>
#include <vector>
using namespace std;

enum Result
{
    FALSE,
    TRUE,
    EMPTY,
};

class Solution
{
public:
    /**
     * 自顶向下的DP算法
     */
    bool isMatch(string text, string pattern)
    {
        this->m_dp = vector<vector<Result>>(text.size() + 1, vector<Result>(pattern.size() + 1, Result::EMPTY));
        // vector<vector<Result>> m_dp(text.size() + 1, vector<Result>(pattern.size() + 1, Result::EMPTY));
        return dp(0, 0, text, pattern);
    }

private:
    vector<vector<Result>> m_dp;

    bool dp(int i, int j, string text, string pattern)
    {
        if (m_dp[i][j] != Result::EMPTY)
        {
            return m_dp[i][j] == Result::TRUE;
        }

        bool ans;

        if (j == pattern.size())
        {
            ans = text.size() == i;
        }
        else
        {
            bool firstMatch = (i < text.size() &&
                               (pattern[j] == text[i] || pattern[j] == '.'));

            if (j + 1 < pattern.size() && pattern[j + 1] == '*')
            {
                ans = (firstMatch && dp(i + 1, j, text, pattern)) || dp(i, j + 2, text, pattern);
            }
            else
            {
                ans = firstMatch && dp(i + 1, j + 1, text, pattern);
            }
        }

        m_dp[i][j] = ans ? Result::TRUE : Result::FALSE;
        return ans;
    }
};