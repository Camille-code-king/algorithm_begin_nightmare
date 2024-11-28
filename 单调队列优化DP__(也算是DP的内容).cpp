class Solution {
    //dp[n]=max(dp[n-k~n])+nums[n]
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>q;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            while(!q.empty()&&i-q.front()>k){
                q.pop_front();
            }
            if(q.empty()||dp[q.front()]<=0)
            dp[i]=nums[i];
            else
            dp[i]=nums[i]+dp[q.front()];
            while(!q.empty()&&dp[i]>=dp[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
