#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    //Brute Force Approach
    //TC -> O(N^3)
    //SC -> O(1)
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int s=0;
                for(int k=i;k<=j;k++) s=s+nums[k];
                m=max(m,s);
            }
        }
        return m;
    }



    //Better Brute Force Approach
    //TC -> O(N^2)
    //SC -> O(1)
    int maxSubarray(vector<int>& nums){
        int n=nums.size();
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s=s+nums[j];
                m=max(m,s);
            }
        }
        return m;
    }




    //Kadane's Algorithm
    //TC -> O(N)
    //SC -> O(1)
    int maxSubarray(vector<int>& nums){
        int n=nums.size();
        int m=nums[0];
        int r=nums[0];
        for(int i=0;i<n;i++){
            m=max(nums[i]+m+nums[i]);
            r=max(r,m);
        }
        return r;
    }

};
