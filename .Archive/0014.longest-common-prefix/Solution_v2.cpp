/**

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include "limits.h"

using namespace std;

class Solution
{
public:
    /**
     * 二分法：对字符串列表按字符串下标二分，再匹配查找
     */
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }

        return _longestCommonPrefix(strs, 0, make_tuple(0, strs[0].size() - 1));
    }

    string _longestCommonPrefix(vector<string> &strs, int commonPrefixIndex, tuple<int, int> range)
    {
        if (get<0>(range) == get<1>(range))
        {
            if (isCommonPrefix(strs, make_tuple(commonPrefixIndex, get<0>(range))))
            {
                return strs[0].substr(0, get<1>(range) + 1);
            }
            else
            {
                return strs[0].substr(0, get<1>(range));
            }
        }

        int mid = (get<0>(range) + get<1>(range)) / 2;
        if (isCommonPrefix(strs, make_tuple(0, mid)))
        {
            return _longestCommonPrefix(strs, mid, make_tuple(mid + 1, get<1>(range)));
        }
        else
        {
            return _longestCommonPrefix(strs, 0, make_tuple(0, mid));
        }
    }

    bool isCommonPrefix(vector<string> &strs, tuple<int, int> range)
    {
        for (int i = get<1>(range); i >= get<0>(range); i--)
        {
            char *c = nullptr;
            for (auto &&str : strs)
            {
                if (i >= str.size())
                {
                    return false;
                }

                if (c == nullptr)
                {
                    c = &str[i];
                }
                if (c != nullptr && str[i] != *c)
                {
                    return false;
                }
            }
        }

        return true;
    }
};