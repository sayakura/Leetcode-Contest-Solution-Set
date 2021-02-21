class Solution {
public:
    bool check(vector<int> &poi, int d, int m) {
        int p = 0;
        int i = 1;
        while (--m) {
            while (i < poi.size() && poi[i] < poi[p] + d)
                ++i;
            if (i >= poi.size()) return false;
            p = i;
        }
        return true;
    }
    int maxDistance(vector<int>& poi, int m) {
        sort(poi.begin(), poi.end());
        if (m == 2) return poi.back() - poi[0];
        int l = 1, r = poi.back() - poi[0];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(poi, mid, m))  l = mid + 1;
            else r = mid - 1;
        }
        return r;        
    }
};

