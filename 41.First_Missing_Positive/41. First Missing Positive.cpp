#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int smallestPositive = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                continue;
            }
            if (nums[i] == smallestPositive) {
                smallestPositive++;
            }
            else if (nums[i] > smallestPositive) {
                return smallestPositive;
            }
        }

        return smallestPositive;
    }
};

int main()
{
    Solution s;
    vector<int>nums = { 3, 4, -1, 1 };
    vector<int>nums1 = { 1, 2, 0 };
    vector<int>nums2 = { 7, 8, 9, 11, 12 };
    vector<int>nums3 = { -3,9,16,4,5,16,-4,9,26,2,1,19,-1,25,7,22,2,-7,14,2,5,-6,1,17,3,24,-4,17,15 };
    cout << s.firstMissingPositive(nums1);
}