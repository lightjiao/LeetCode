#include <vector>
#include <iostream>
#include "Solution_v2.cpp"

using namespace std;

void testCase(vector<int> height, int expect)
{
    int result = (Solution()).maxArea(height);

    cout << "expect: " << expect << ", "
         << "result: " << result;

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
    testCase({1, 8, 6, 2, 5, 4, 8, 3, 7}, 49);
    return 0;
}