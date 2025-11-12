#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // -------------------------------------------------------
    // 🧩 Brute Force Approach
    // TC -> O(N^2)
    // SC -> O(1)
    // -------------------------------------------------------
    int maxProductBrute(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = i; j < n; j++) {
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }

        return ans;
    }

    // -------------------------------------------------------
    // ⚡ Better Approach (Prefix–Suffix Trick)
    // TC -> O(N)
    // SC -> O(1)
    // -------------------------------------------------------
    // Idea: Sometimes the max product lies after a zero or negative segment.
    // So, we compute product from left-to-right and right-to-left and take max.
    int maxProductBetter(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1, suffix = 1;
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            // if zero resets the product
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            ans = max({ans, prefix, suffix});
        }

        return ans;
    }

    // -------------------------------------------------------
    // 🚀 Optimal Approach (Kadane’s for Product)
    // TC -> O(N)
    // SC -> O(1)
    // -------------------------------------------------------
    // Keep track of both current max and min products
    // because negative × negative becomes positive.
    int maxProductOptimal(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < n; i++) {
            int temp = currMax;
            currMax = max({nums[i], nums[i] * currMax, nums[i] * currMin});
            currMin = min({nums[i], nums[i] * temp, nums[i] * currMin});
            ans = max(ans, currMax);
        }

        return ans;
    }
};

// -------------------------------------------------------
// 🔍 Driver Code Example
// -------------------------------------------------------
int main() {
    vector<int> nums = {2, 3, -2, 4};

    Solution obj;

    cout << "Brute Force: " << obj.maxProductBrute(nums) << endl;
    cout << "Better (Prefix-Suffix): " << obj.maxProductBetter(nums) << endl;
    cout << "Optimal (Kadane): " << obj.maxProductOptimal(nums) << endl;

    return 0;
}
