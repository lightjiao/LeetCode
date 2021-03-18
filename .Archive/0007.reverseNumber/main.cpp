#include <vector>
#include <iostream>
#include "reverse.cpp"

using namespace std;

void testCase(int number, int expect)
{
    int result = (Solution()).reverse(number);

    cout << "expect: " << expect << ", "
         << "result: " << result;

    if (result == expect)
    {
        cout << " true" << endl;
    }
    else
    {
        cout << " false" << endl;
        //<< "expect: " << expect << ", "
        //<< "result: " << result << endl;
    }
}

int main()
{
    testCase(123, 321);
    testCase(-123, -321);
    testCase(120, 21);
    testCase(1534236469, 0);
    return 0;
}