class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ret = 0;
        unordered_map<int, vector<int>> hm;
        
        for (int i = 0; i < nums.size(); i++) 
            hm[nums[i]].push_back(i);
        for (auto itr : hm) {
            if (itr.second.size() > 1) {
                int t = (1 + (itr.second.size() - 1) ) * (itr.second.size() - 1) / 2;  
                ret += t;
            }
        }
        return ret;
    }
};