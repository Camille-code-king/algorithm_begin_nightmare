class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int r=n-2;
        if(target>nums[n-1]){
            l=1;
            r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]>target)r=mid-1;
                else if(nums[mid]<target&&nums[mid]<=nums[n-1])r=mid-1;
                else l=mid+1;
            }
            return nums[r]==target?r:-1;
        }else{
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[mid]<target)l=mid+1;
                else if(nums[mid]>=target&&nums[mid]<=nums[n-1])r=mid-1;
                else l=mid+1;
            }
            return nums[l]==target?l:-1;
        }
    }
};   
