#include "4-findMedianSortedArrays.cpp"
#include <vector>
#include <iostream>

using namespace std;
void testCase(vector<int> nums1, vector<int> nums2, double expect)
{
    double result = (Solution()).findMedianSortedArrays(nums1, nums2);
    if (result == expect)
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
    testCase(vector<int>{1, 2}, vector<int>{2 }, 2.0);
    testCase(vector<int>{1, 3}, vector<int>{2 }, 2.0);
    testCase(vector<int>{1, 2}, vector<int>{3, 4 }, 2.5);
    return 0;
}