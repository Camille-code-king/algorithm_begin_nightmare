class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n=points.size();
        int ans=INT_MIN;
        deque<int>q;
        int i=0;
        for(int j=0;j<n;j++){
            int sumj=points[j][0]+points[j][1];
            int j1=points[j][1]-points[j][0];
            while(!q.empty()&&points[j][0]-points[q.front()][0]>k){
                q.pop_front();
            }
            if(!q.empty())
            ans=max(ans,sumj+points[q.front()][1]-points[q.front()][0]);
            while(!q.empty()&&j1>points[q.back()][1]-points[q.back()][0]){
                q.pop_back();
            }
            q.push_back(j);
        }
        return ans;
    }
};
