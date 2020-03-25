#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m;
        vector<int> v(2, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int complete = target - nums[i];
            map<int, int>::iterator it = m.find(complete);
            if (it != m.end())
            {
                v[0] = i;
                v[1] = m[complete];
                break;
            }
            m.insert(pair<int, int>(nums[i], i));
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
