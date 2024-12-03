class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        auto dfs=[&](auto&&dfs,int left,int right,string a,int count){
            if(right==s.size()){
                if(count==4)
                ans.push_back(a);
                return;
            }
            if(count==4)return;
            if(s[left]=='0'&&left!=right)return;
            int len=right-left+1;
            if(len>3)return;
            int cur=stoi(s.substr(left,len));
            dfs(dfs,left,right+1,a,count);
            if(cur<=255&&count<3)dfs(dfs,right+1,right+1,a+=s.substr(left,len)+".",++count);
            else if(cur<=255&&count==3)dfs(dfs,right+1,right+1,a+=s.substr(left,len),++count);
        };
        dfs(dfs,0,0,"",0);
        return ans;
    }
};
