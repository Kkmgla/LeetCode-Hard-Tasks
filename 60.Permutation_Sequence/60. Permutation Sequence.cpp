#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {

        int i = 1;
        vector<int>nums;
        string result = "";
        int numResult = 0;

        while (i <= n)
        {
            nums.push_back(i);
            i++;
        }

        for (int j = 0; j < k - 1; j++) next_permutation(nums.begin(), nums.end());
        for (int x = 0; x < nums.size(); x++) result.append(to_string(nums[x]));

        return result;
    }
};

int main()
{
    Solution s;
    int n = 3; // quantity of digits
    int k = 3; // iteration
    cout << s.getPermutation(n, k);
}