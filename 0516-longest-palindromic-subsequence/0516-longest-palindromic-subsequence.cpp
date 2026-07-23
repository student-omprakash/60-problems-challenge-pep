class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m=s.size();
       // string sr=reverse(s.begin(),s.end());
       string sr(s.rbegin(), s.rend()); // creates a new reversed string

        int dp[m+1][m+1];
        for(int i=0;i<=m;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==sr[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
};