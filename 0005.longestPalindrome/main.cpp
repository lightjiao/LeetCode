#include <vector>
#include <iostream>
#include "longestPalindrome.cpp"
using namespace std;

void testCase(string s, string expect)
{
    string result = (Solution()).longestPalindrome(s);
    if (0 == result.compare(expect))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false: "
            << "expect: " << expect << ", "
            << "result: " << result << endl;
    }
}

int main()
{
    testCase("babad", "bab");
    testCase("cbbd", "bb");
    testCase("ada", "ada");
    testCase("abcdefg", "a");
    return 0;
}