#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Brute Force Approach
    //TC -> O(N^2)
    //SC -> O(1)
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) 
                if(nums[i]==nums[j])return true;
        }
        return false;
    }


    //Using HashSet
    //TC -> O(N)
    //SC -> O(N)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num:nums) {
            if(seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }


    //Sorting Approach
    //TC -> O(NlogN)
    //SC -> O(1)
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++) 
            if(nums[i] == nums[i - 1]) return true;
        return false;
    }
};
