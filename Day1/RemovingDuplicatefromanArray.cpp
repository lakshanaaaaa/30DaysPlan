#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Using STL
    //TC -> O(N)
    //SC -> O(1)
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        return it - nums.begin(); // number of unique elements
    }

    //Using set
    //TC -> O(NlogN)
    //SC -> O(N)
    int removeDuplicates(vector<int>& nums){
        set<int> s;
        for(int i=0;i<nums.siz();i++) s.insert(nums[i]);
        return s.size();
    }

    
    //Two Pointer Approach
    //TC -> O(N)
    //SC -> O(1)
    int removeDuplicates(vector<int>& nums)[
        int n=nums.size();
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    ]
};
