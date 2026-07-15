class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int diff;
        int maxi=INT_MIN;
        for(int i=0;i<prices.size();i++){
            mini=min(mini,prices[i]);
            diff=prices[i]-mini;
            maxi=max(maxi,diff);
        }
        return maxi;
        
    }
};