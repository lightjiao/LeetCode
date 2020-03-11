#include <vector>
#include <iostream>
#include "Solution_v2.cpp"

using namespace std;

void testCase(vector<string> strs, string expect)
{
    string result = (Solution()).longestCommonPrefix(strs);

    if (result.compare(expect) == 0)
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
    testCase({"flower", "flow", "flight"}, "fl");
    testCase({"dog", "racecar", "car"}, "");
    testCase({"a"}, "a");
    testCase({"a", "a"}, "a");
    testCase({"abc", "abc"}, "abc");
    testCase({"ab"}, "ab");
    testCase({"abc"}, "abc");
    testCase({"ac", "ab"}, "a");
    return 0;
}