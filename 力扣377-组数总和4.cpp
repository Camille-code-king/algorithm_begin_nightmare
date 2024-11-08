class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int numn=nums.size();
        vector<int>memo(target+1,-1);
        auto f=[&](auto&& f,int t){
            int sum=0;
            if(t<0)return 0;
            if(t==0)return 1;
            if(memo[t]!=-1)return memo[t];
            for(int i=0;i<numn;i++){
                sum+=f(f,t-nums[i]);
            }
            return memo[t]=sum;
        };
    return f(f,target);
    }
};
