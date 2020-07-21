/*
    link: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ret(n);
        vector<bool> visited(n , false); // another approach is to use "ret" as "visited" instead, 
                                         // if ret[i] != -1 something like that, since ret[i] will be set after ith node is visited
        int cnt[26] = { 0 };             // int[] is faster than vector

        unordered_map<int, vector<int>> G;
        for (auto &e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        dfs(0, visited, G, cnt, labels, ret);
        return ret;
    }
    void dfs(int cur, vector<bool> &visited, unordered_map<int, vector<int>> &G, int cnt[], string &labels, vector<int> &ret) {
        if (!visited[cur]) {
            visited[cur] = true;
            for (int nei : G[cur]) {
                if (!visited[nei]) {
                    int tcnt[26] = { 0 };
                    dfs(nei, visited, G, tcnt, labels, ret); 
                    for (int i = 0; i < 26; i++)
                        cnt[i] += tcnt[i];
                }
            }
            ret[cur] = ++cnt[labels[cur] - 'a'];
        }
    }
};