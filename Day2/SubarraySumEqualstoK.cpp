#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    //Brute Force Approach
    //TC -> O(N^3)
    //SC -> O(1)
    int subarraySum(vector<int>& nums,int k){
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int s=0;
                for(int k=i;k<=j+1;k++) s=s+nums[k];
                if(s==k) c++;
            }
        }
        return c;
    }



    //Better Brute Force Approach
    //TC -> O(N^2)
    //SC -> O(1)
    int subarraySum(vectot<int>& nums,int k){
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s=s+nums[j];
                if(s==k) c++;
            }
        }
        return c;
    }

    //Optimal Approach using HashMap
    //TC -> O(N)
    //SC -> O(N)
    int subarraySum(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int> mp;
        int s=0;
        int c=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            s=s+nums[i];
            if(mp.find(s-k)!=mp.end()){
                c=c+mp[s-k];
            }
            mp[s]++;
        }
        return c;
    }
};
