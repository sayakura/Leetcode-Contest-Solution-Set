// link: https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        
        int num = 1;
        for (int i = 0; i < n; i++) {
            ret[i] = num;
            if (num * 10 <= n) {
                num *= 10;
            } else {
                if (num >= n)
                    num /= 10;
                num += 1;
                while (num % 10 == 0)
                    num /= 10;
            }
        }
        return ret;    
    }

    vector<int> lexicalOrder2(int n) {
        vector<int> ret;

        for (int i = 1; i < 10; i++) 
            dfs(i, n, ret);
        return ret;
    }
    void dfs(int cur, int n, vector<int> &ret) {
        if (cur > n)
            return ;
        for (int i = 0; i < 10; i++) {
            if (cur * 10 + i > n)
                return ;
            ret.push_back(cur);
            dfs(cur * 10 + i, n, ret);
        }
    }
};