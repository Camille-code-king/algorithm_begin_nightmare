class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        auto dfs=[&](auto&&dfs,int rest,int num,vector<int>path){
            if(rest>n-num+1)return;
            if(rest==0){
                ans.push_back(path);
                return;
            }
            dfs(dfs,rest,num+1,path);
            path.push_back(num);
            dfs(dfs,rest-1,num+1,path);
        };
        dfs(dfs,k,1,{});
        return ans;
    }
};
