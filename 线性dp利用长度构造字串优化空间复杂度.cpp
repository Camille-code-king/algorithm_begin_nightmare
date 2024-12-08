class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else{
                dp[i][j]=min(dp[i][j-1],dp[i-1][j])+1;
                }
            }
        }
        string ans;
        int  i=n,j=m;
        while(i>=1&&j>=1){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                --i;--j;
            }else if(dp[i][j]==dp[i-1][j]+1){
                ans+=str1[i-1];
                i--;
            }else {
                ans+=str2[j-1];
                j--;
            }
        }
        reverse(ans.begin(),ans.end());
        return str1.substr(0,i)+str2.substr(0,j)+ans;
    }
};
