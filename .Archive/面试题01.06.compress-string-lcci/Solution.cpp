/**
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
比如，字符串aabcccccaaa会变为a2b1c5a3。
若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。
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
     * 直接拼接
     */
    string compressString(string s)
    {
        string result;
        if (s.size() == 0) {
            return result;
        }

        int charCount = 1;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                result += s[0];
                continue;
            }

            if (s[i] == s[i - 1]) {
                charCount++;
            }
            else {
                result += to_string(charCount);
                result += s[i];
                charCount = 1;
            }
        }
        result += to_string(charCount);

        return result.size() < s.size() ? result : s;
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.compressString("aabcccccaaa") == "a2b1c5a3");
    REQUIRE(s.compressString("aabcccccaa") == "a2b1c5a2");
    REQUIRE(s.compressString("abbccd") == "abbccd");
}
