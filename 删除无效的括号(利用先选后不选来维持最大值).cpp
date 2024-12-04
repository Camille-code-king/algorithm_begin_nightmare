class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string>ans;
        string path;
        int maxv=0;
        auto dfs=[&](auto&&dfs,int i,int left,int right){
            if(i==s.size()){
                if(path.size()>=maxv&&right==left){
                maxv=path.size();
                ans.insert(path);
                }
                return;
            }
            if(s[i]!='('&&s[i]!=')'){
                path.push_back(s[i]);
                dfs(dfs,i+1,left,right);
                path.pop_back();
            }
            else if(left>=right){
                if(s[i]=='('){
                path.push_back(s[i]);
                dfs(dfs,i+1,left+1,right);
                path.pop_back();
                dfs(dfs,i+1,left,right);
                }
                else{
                path.push_back(s[i]);
                dfs(dfs,i+1,left,right+1);
                path.pop_back();
                dfs(dfs,i+1,left,right);
                }
            }
        };
        dfs(dfs,0,0,0);
        vector<string>res;
        for(string a:ans){
            res.push_back(a);
        }
        return res;
    }
};
