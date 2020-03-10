#include <vector>
#include <iostream>
#include "Solution_v4_dp2.cpp"

using namespace std;

void testCase(string s, string p, bool expect)
{
    int result = (Solution()).isMatch(s, p);

    cout << "expect: " << expect << ", " << "result: " << result;

    if (result == expect)
    {
        cout << " ok" << endl;
    }
    else
    {
        cout << " error" << endl;
    }
}

int main()
{
    testCase("aa", "a", false);
    testCase("aa", "aa", true);
    testCase("aa", "..", true);
    testCase("aa", "a*", true);
    testCase("ab", "..", true);
    testCase("aab", "c*a*b", true);
    testCase("mississippi", "mis*is*p*.", false);
    testCase("mississippi", "mis*is*ip*.", true);

    testCase("ab", ".*", true);
    testCase("ab", ".*c", false);

    testCase("aaa", "a*a", true);

    testCase("adaskdhaskdhqsjkdjhqwoe", ".*", true);
    return 0;
}