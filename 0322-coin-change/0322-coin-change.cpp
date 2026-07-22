class Solution {
public:
   int memo(int i,vector<int>&coins,int amount,vector<vector<int>>&dp)
   {
      if(amount==0) return 0;
      if(i<0) return INT_MAX;
      if(dp[i][amount]!=-1) return dp[i][amount];
      int take=INT_MAX;
      if(coins[i]<=amount){
        int result=memo(i,coins,amount-coins[i],dp);
        //take=memo(i,coins,amount-coins[i],dp);
        if(result!=INT_MAX){
            take=1+result;
        }

      }
      int nottake=memo(i-1,coins,amount,dp);
      return dp[i][amount]=min(take,nottake);



   }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));
       int ans= memo(n-1,coins,amount,dp);
       if(ans==INT_MAX) return -1;
       return ans;
    }
};