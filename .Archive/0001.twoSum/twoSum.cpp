#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v(2, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {

                if (nums[i] + nums[j] != target)
                    continue;
                v[0] = i;
                v[1] = j;
                break;
            }
        }

        return v;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> v = s.twoSum(nums, target);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
