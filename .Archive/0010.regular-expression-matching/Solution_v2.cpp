#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(string text, string pattern)
    {
        if (pattern.size() == 0)
        {
            return text.size() == 0;
        }

        bool firstMatch = (text.size() != 0 &&
                           (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.size() >= 2 && pattern[1] == '*')
        {
            return (
                isMatch(text, pattern.substr(2)) ||
                (firstMatch &&
                 isMatch(text.substr(1), pattern)));
        }
        else
        {
            return firstMatch && isMatch(text.substr(1), pattern.substr(1));
        }
    }
};