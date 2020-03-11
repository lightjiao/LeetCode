#include <vector>
#include <iostream>
#include "Solution.cpp"

using namespace std;

void testCase(vector<string> strs, string expect)
{
    string result = (Solution()).longestCommonPrefix(strs);

    cout << "expect: " << expect << ", "
         << "result: " << result;

    if (result.compare(expect) == 0)
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
    testCase({"flower", "flow", "flight"}, "fl");
    testCase({"dog", "racecar", "car"}, "");
    return 0;
}