class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long n=chargeTimes.size();
        deque<long long>q;
        long long l=0;
        long long sum=0;
        long long ans=0;
        for(long long r=0;r<n;r++){
            while(!q.empty()&&chargeTimes[r]>chargeTimes[q.back()]){
                q.pop_back();
            }
            q.push_back(r);
            sum+=runningCosts[r];
            while(!q.empty()&&(l>q.front()||chargeTimes[q.front()]+(r-l+1)*sum>budget)){
                if(!q.empty()&&chargeTimes[q.front()]+(r-l+1)*sum>budget){
                    sum-=runningCosts[l];
                    l++;
                }
                if(!q.empty()&&l>q.front()){
                    q.pop_front();
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
