#include <vector>
#include <iostream>
#include "isPalindrome.cpp"

using namespace std;

void testCase(int x, bool expect)
{
    int result = (Solution()).isPalindrome(x);

    cout << "expect: " << expect << ", " << "result: " << result;

    if (result == expect)
    {
        cout << " true" << endl;
    }
    else
    {
        cout << " false" << endl;
    }
}

int main()
{
    testCase(42, false);
    testCase(121, true);
    testCase(-121, false);
    testCase(10, false);
    return 0;
}