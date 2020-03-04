#include <vector>
#include <iostream>
#include "ZConvert.cpp"
using namespace std;

void testCase(string s, int numRows, string expect)
{
    string result = (Solution()).convert(s, numRows);
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
    testCase("0123456", 3, "0413526");
    testCase("LEETCODEISHIRING", 3, "LCIRETOESIIGEDHN");
    testCase("LEETCODEISHIRING", 4, "LDREOEIIECIHNTSG");
    testCase("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    return 0;
}