class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int m=2*n;
        vector<string>ans;
        string path(m,0);
        auto dfs=[&](auto&&dfs,int i,int open){
            if(i==m){
                ans.push_back(path);
                return;
            }
            if(open<n){
                path[i]='(';
                dfs(dfs,i+1,open+1);
            }
            if(i-open<open){
                path[i]=')';
                dfs(dfs,i+1,open);
            }
        };
        dfs(dfs,0,0);
        return ans;
    }
};
