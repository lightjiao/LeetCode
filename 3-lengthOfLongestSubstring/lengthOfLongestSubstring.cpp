#include <string>
#include <map>
#include <algorithm>

using namespace std;

/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            string subString = s.substr(i, string::npos);
            int _len = this->_lengthOfLongestSubstring(subString);
            len = max(len, _len);
        }

        return len;
    }

private:
    int _lengthOfLongestSubstring(string s)
    {
        char firstChar = s[0];
        map<char, bool> repeatCharMap = { pair<char, bool>(firstChar, true) };

        int len = 1;
        for (int i = 1; i < s.length(); i++)
        {
            map<char, bool>::iterator it = repeatCharMap.find(s[i]);
            if (it != repeatCharMap.end())
            {
                break;
            }

            len++;
            repeatCharMap.insert(pair<char, int>(s[i], true));
        }

        return len;
    }
};