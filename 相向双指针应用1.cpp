class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        int l=0,r=n-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum>=target)
                r--;
            else{
            count=count+r-l;
            l++;
            r=n-1;
            }
        } 
        return count;                                          
    }
};
