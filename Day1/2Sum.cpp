#include <bits/stdc++.h>
using namespace std;


//BRUTE FORCE APPROACH
//TC -> O(N^2)
//SC -> O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target) return {i,j};
        }
    }
    return {};
}


//OPTIMIZED APPROACH
//TC -> O(N)    
//SC -> O(N)
vector<int>twoSum(vector<int>& nums,int target){
    int n=nums.size();
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        int c=target-nums[i];
        if(m.find(c)!=m.end()) return{m[c],i};
        m[nums[i]]=i;
    }
    return {};
}


//OPTIMIZED APPROACH  TWO POINTERS
//TC -> O(NlogN)
//SC -> O(N)
vector<int> twoSum(vector<int> &nums, int target){
    int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            int c=target-v[i].first;
            int l=i+1,r=n-1;
            while(l<=r){
                int m=(l+r)/2;
                if(v[m].first==c) return {v[i].second,v[m].second};
                else if(v[m].first<c) l=m+1;
                else r=m-1;
            }
        }
        return {};
}


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1];
}
