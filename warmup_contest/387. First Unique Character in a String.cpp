// https://leetcode.com/problems/first-unique-character-in-a-string/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int mp[26] = { 0 };
        for (char c : s) 
            mp[c - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }

    int firstUniqChar2(string s) {
        vector<pair<int, int>> dp(26);
        for (int i = 0; i < s.size(); i++) {
            dp[s[i] - 'a'].first++;
            dp[s[i] - 'a'].second = i;
        }
        int ret = INT_MAX;
        for (auto &p : dp) {
            if (p.first == 1)
                ret = min(ret, p.second);
        }
        return ret == INT_MAX ? -1 : ret;
    }

    int firstUniqChar3(string s) {
        int cnt[26] = {0};
        int poi[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            poi[s[i] - 'a'] = i;
        }
        int ret = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 1)
                ret = min(ret, poi[i]);
        }
        return ret == INT_MAX ? -1 : ret;
    }
};