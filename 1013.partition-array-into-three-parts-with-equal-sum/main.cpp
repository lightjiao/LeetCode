#include <vector>
#include <iostream>
#include "Solution.cpp"

using namespace std;

void testCase(vector<int> A, bool expect)
{
    bool result = (Solution()).canThreePartsEqualSum(A);

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
    testCase({1, 1, 1}, true);
    testCase({1, -1, 1, -1}, false);
    testCase({0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1}, true);
    testCase({0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1}, false);
    testCase({3, 3, 6, 5, -2, 2, 5, 1, -9, 4}, true);
    testCase({18, 12, -18, 18, -19, -1, 10, 10}, true);
    return 0;
}