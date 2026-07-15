class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd,even=0;
       // int mini=0;
        for(int i=0;i<position.size();i++){
            if(position[i]%2==0) even++;
            else odd++;
        }
     //mini=min(odd,even);
     if(odd>=even) return even;
     else
     return odd;

        
    }
};