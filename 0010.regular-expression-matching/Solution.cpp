#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        cout << "this is a wrong answer.";
        return false;

        if (s.size() == 0 && p.size() > 0)
        {
            return false;
        }

        int patternIndex = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // s 没有匹配结束，但是pattern已经匹配结束则匹配失败
            if (patternIndex >= p.size())
            {
                return false;
            }

            char pattern = p[patternIndex];

            // 下一个坐标是否是*
            bool repeatPattern = (patternIndex + 1 < p.size() && p[patternIndex + 1] == '*');
            if (pattern != s[i] && pattern != '.')
            {
                // 匹配失败但是* 匹配，则跳过* 往下匹配
                if (repeatPattern)
                {
                    i--;
                    patternIndex += 2;
                }
                else
                {
                    return false;
                }
            }

            // 匹配成功并且不是带* 的匹配，则pattern 下标 + 1
            if (!repeatPattern)
            {
                patternIndex++;
            }
        }

        // pattern是否结束 -- error in aaa & a*a
        while (patternIndex < p.size())
        {
            bool repeatPattern = (patternIndex + 1 < p.size() && p[patternIndex + 1] == '*');
            if (!repeatPattern)
            {
                return false;
            }
            else
            {
                patternIndex += 2;
            }
        }

        return true;
    }
};