class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<int>right(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[i]<nums[st.top()]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        st=stack<int>();
        vector<int>left(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<nums[st.top()]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(left[i]<=k-1&&right[i]>=k+1){
            int width=right[i]-left[i]-1;
            ans=max(ans,width*nums[i]);
            }
        }
        return ans;
    }
};
