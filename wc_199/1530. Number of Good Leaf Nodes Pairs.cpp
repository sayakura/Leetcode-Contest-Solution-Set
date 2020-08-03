/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ret = 0;
    bool isLeaf(TreeNode *root) {
        return !root->left && !root->right;
    }
    vector<int> helper(TreeNode *root, int dist) {
        if (!root->left && !root->right)
            return {};
        vector<int> l, r;
        if (root->left) {
            l = helper(root->left, dist);
            if (l.size() == 0)
                l.push_back(1);
        }
        if (root->right) {
            r = helper(root->right, dist);
            if (r.size() == 0)
                r.push_back(1);
        }
        for (auto ll : l) {
            for (auto rr : r) {
                if (ll + rr <= dist)
                    ret++;
            }
        }
        for (int i = 0; i < l.size(); i++)
            l[i]++;
        for (int i = 0; i < r.size(); i++) 
            l.push_back(r[i] + 1);
        return l;
    }
    int countPairs(TreeNode* root, int distance) {
        ret = 0;
        helper(root, distance);
        return ret;
    }
};