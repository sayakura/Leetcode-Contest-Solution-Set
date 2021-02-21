class Solution {
public:
    bool check(vector<int> &arr, bool incre) {
        for (int n : arr) {
            if (n % 2 == 0 && incre) return false ;
            if (n % 2 != 0 && !incre) return false ;
        }
        if (arr.size() <= 1) return true;
        for (int i = 1; i < arr.size(); i++) {
            if (incre && arr[i] <= arr[i - 1]) return false ;
            if (!incre && arr[i] >= arr[i - 1]) return false ;
        }
        return true;        
    }
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q;
        int level = 0;
        q.push(root);
        while (!q.empty()) {
            int siz = q.size();
            vector<int> arr;
            while (siz--) {
                auto v = q.front();
                arr.push_back(v->val);
                q.pop();
                if (v->left)
                    q.push(v->left);
                if (v->right)
                    q.push(v->right);
            }
            if (!check(arr, level % 2 == 0)) return false ;
            level++;
        }
        return true;
    }
};