#include <vector>
#include <iostream>
#include "Solution_v3.cpp"

using namespace std;

void testCase(string str1, string str2, string expect)
{
    string result = (Solution()).gcdOfStrings(str1, str2);

    if (result == expect)
    {
        cout << " ok ";
    }
    else
    {
        cout << " error ";
    }

    cout << "expect: " << expect << ", "
         << "result: " << result << endl;
}

int main()
{
    testCase("ABCABC", "ABC", "ABC");
    testCase("ABABAB", "ABAB", "AB");
    testCase("LEET", "CODE", "");
    return 0;
}