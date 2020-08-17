class Solution {
public:
   unordered_map<int, int> dp;
    int minDays(int n) {
        if (n <= 1)
            return n;
        if (dp.count(n) == 0)
            dp[n] = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return dp[n];
    }


    int minDays(int n) {
         unordered_set<int> visited;
         queue<int> q;
         int level = 1;
         q.push(n);
         
         while (!q.empty()) {
             int siz = q.size();
             while (siz--) {
                 int cur = q.front(); q.pop();
                 if (cur == 1)
                     return level;
                 visited.insert(cur);
                 if (visited.find(cur - 1) == visited.end())
                     q.push(cur - 1);
                 if (cur % 2 == 0 and visited.find(cur / 2) == visited.end())
                     q.push(cur / 2);
                 if (cur % 3 == 0 and visited.find(cur / 3) == visited.end())
                     q.push(cur / 3);
             }
             level++;
         }
         return level;
     }
};