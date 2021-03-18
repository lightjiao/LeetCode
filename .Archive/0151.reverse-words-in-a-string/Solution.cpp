/**
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
进阶：
请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do
                           // this in one cpp file
#include "../ListNode.cpp"
#include "../VV.cpp"
#include "../catch.hpp"

#include "limits.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string result;
        if (s.size() == 0) {
            return result;
        }

        vector<string> words;

        bool isWord       = (s[0] != ' ');
        int  wordStartPos = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (isWord) {
                    auto word = string(s.begin() + wordStartPos, s.begin() + i);
                    words.push_back(word);
                    isWord = false;
                }
                
                wordStartPos = i + 1;
            }
            else {
                isWord = true;
            }
        }

        if (isWord) {
            auto word = string(s.begin() + wordStartPos, s.end());
            words.push_back(word);
        }

        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            if (i != 0) {
                result += " ";
            }
        }

        return result;
    }
};

TEST_CASE("test")
{
    Solution s;
    REQUIRE(s.reverseWords("the sky is blue") == "blue is sky the");
    REQUIRE(s.reverseWords("  hello world!  ") == "world! hello");
    REQUIRE(s.reverseWords("a good   example") == "example good a");
}
