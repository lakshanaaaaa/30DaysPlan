#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Brute Force Approach
    //TC -> O(N)
    //SC -> O(N)
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        
        // Step 1: Store all non-zero elements
        for(int i=0;i<n;i++) 
            if(nums[i] != 0) temp.push_back(nums[i]);

        // Step 2: Fill remaining with zeros
        while(temp.size()<n) 
            temp.push_back(0);

        // Step 3: Copy back to original array
        for(int i=0;i<n;i++) 
            nums[i]=temp[i];

    }


    //Two Pointer Approach
    //TC -> O(N)
    //SC -> O(1)
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0; 
        for(int j=0;j<n;j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }
    }
    

    //Optimized Swap Approach
    //TC -> O(N)    
    //SC -> O(1)
     void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }


};
