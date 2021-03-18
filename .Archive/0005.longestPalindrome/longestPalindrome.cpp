/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string starStr = "*";
        for (auto &c : s)
        {
            starStr += c;
            starStr += "*";
        }

        string starResultStr = "";
        for (int i = 0; i < starStr.size(); i++)
        {
            string tempStarResultStr = getPalindromeOfPos(starStr, i);
            if (starResultStr.size() < tempStarResultStr.size())
            {
                starResultStr = tempStarResultStr;
            }
        }

        string resultStr;
        for (int i = 0; i < starResultStr.size(); i++)
        {
            if (i % 2 == 0)
                continue;
            resultStr += starResultStr[i];
        }

        return resultStr;
    }

private:
    string getPalindromeOfPos(string s, int pos)
    {
        if (pos == 0 || pos == s.size() - 1)
        {
            return s.substr(pos, 1);
        }

        int slide = 0;
        while (pos - slide >= 0 && pos + slide < s.size())
        {
            if (s[pos - slide] != s[pos + slide])
            {
                slide--;
                break;
            }

            slide++;
        }
        if (pos - slide < 0 || pos + slide >= s.size())
            slide--;

        return s.substr(pos - slide, slide + slide + 1);
    }
};