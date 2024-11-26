class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&height[i]>=height[st.top()]){
                int last=st.top();
                st.pop();
                if(st.empty())break;
                int left=st.top();
                int high=min(height[left],height[i])-height[last];
                ans+=high*(i-1-left);
            }
            st.push(i);
        }
        return ans;
    }
};
