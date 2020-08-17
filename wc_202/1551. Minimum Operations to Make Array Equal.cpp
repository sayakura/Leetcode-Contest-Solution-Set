class Solution {
public:
    int minOperations(int n) {
        int ret = 0;
        for (int i = 0; i < n / 2; i++) {
            int j = (2 * i) + 1;
            ret += n - j;
        }
        return ret;
    }
 };