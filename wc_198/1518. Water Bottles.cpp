// link: https://leetcode.com/contest/weekly-contest-198/problems/water-bottles/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int times = numBottles;
        
        while (numBottles >= numExchange) {
            int drunken = numBottles / numExchange;
            times += drunken;
            numBottles = drunken + (numBottles % numExchange);
        }
        return times;
    }
};