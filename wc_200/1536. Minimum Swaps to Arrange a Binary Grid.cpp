/*
https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
greedy 算法
因为他要右边的0呈阶梯式递减， 所以这个题目变成计算需要多少个swap 能把那个row swap到当前的row
因为每次都找最近的row（每次都只能swap adjecent的row）, 所以保证每次是最少的
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int n = grid.size();
        int ret = 0;
        vector<int> zeros(n, 0);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && !grid[i][j]; j--)
                cnt++;
            zeros[i] = cnt;
        }
        for (int i = 0; i < n; i++) {
            int need = n - (i + 1), target = i;
            if (need <= zeros[i]) continue ;            // skip if we alreay had enough zeros, cuz we are going top-down so we wont "waste" extra zeros
            while (target < n && zeros[target] < need)  // less than need, it is ok if target contains more than what we need, it cant be exacaly how much we need (think about all zero grid...)
                target++;
            if (target == n) return -1;
            ret += target - i;                          // calculate how many swaps are needed, and accumalte it
            while (target > i) {                        // simulate the swap
                swap(zeros[target - 1], zeros[target]); // zeros[target] = zeros[target - 1] also works, bc we dont need the current row anymore 
                target--;
            }
        }       
        return ret;
    }
};