/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Äëÿ std::sort è std::merge

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        double result = 0.0;
        int n = merged.size();
        if (n % 2 == 0) {
            result = (merged[n / 2] + merged[n / 2 - 1]) / 2.0;
        }
        else {
            result = merged[n / 2];
        }
        return result;
    }
};//0123456
int main()
{
    Solution s;
    vector<int>nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    vector<int>nums2;
    nums2.push_back(4);
    nums2.push_back(5);
    nums2.push_back(6);
    cout << s.findMedianSortedArrays(nums1, nums2);
}

