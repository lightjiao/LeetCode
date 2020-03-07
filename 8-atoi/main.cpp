#include <vector>
#include <iostream>
#include "atoi.cpp"

using namespace std;

void testCase(string str, int expect)
{
    int result = (Solution()).myAtoi(str);

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
    testCase("42", 42);
    testCase("   -42", -42);
    testCase("4193 with words", 4193);
    testCase("words and 987", 0);
    testCase("-91283472332", INT_MIN);

    return 0;
}