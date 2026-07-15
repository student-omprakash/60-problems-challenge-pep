class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count=numBottles;
        int empty=numBottles;
        while(numExchange<=empty){
            count+=empty/numExchange;
            empty=empty/numExchange+empty%numExchange;
        }
        return count;    
    }
};