class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_set<int> hm = { 0 };
        int ret = 0, sum = 0;
        
        for (int n : nums) {
            sum += n;
            if (hm.find(sum - target) != hm.end()) {
                ret++;
                sum = 0;
                hm = { 0 };
            }
            hm.insert(sum);
        }
        return ret;
    }
};