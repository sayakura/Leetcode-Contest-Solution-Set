/*
 https://leetcode.com/problems/get-the-maximum-score/
这题一眼下去的直觉基本上就是答案
要注意的一点是，每次前进的时候，要一步一步走， nums1[j] 如果比nums2[i] 小，那么下一次j就得走
因为每个step都check， 进去else 的时候就是我们判断两个branch 哪个分数更多的时候，sum 加上分多的那个 branch 
不要忘了加相同的那个数
*/


class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long i, j, n = nums1.size(), m = nums2.size(), sum, mod = 1e9 + 7, a, b;
        a = b = i = j = sum = 0;
        
        while (i < n || j < m) {
            if (i < n && (j == m || nums1[i] < nums2[j]))
                a += nums1[i++];
            else if (j < m && (i == n || nums2[j] < nums1[i])) 
                b += nums2[j++];
            else {
                sum += max(a, b) + nums1[i];
                a = b = 0;
                i++; j++;
            }
        }
        return (sum + max(a, b)) % mod; 
    }
};