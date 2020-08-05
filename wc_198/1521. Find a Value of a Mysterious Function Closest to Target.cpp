/*
https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/

这题主要是怎样用嵌套的forloop 把计算后的结果覆盖原 array 这样能把复杂度从 On3 降到 On2， 
然后那个break 能减去很多重复的计算
因为内部的loop 是从 i...j 到 0 .. i ..j走，如果右边 arr[j + 1]早就是0, 那么左边加多一个element 也会变成0
往左继续走下去也是加更多的element ， 而0 & 谁都是0， 所以直接break 就vans
*/

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int res = INT_MAX;
        
        for (int i = 0; i < arr.size(); i++) {
            res = min(res, abs(target - arr[i]));
            for (int j = i - 1; j >= 0; j--) {
                arr[j] &= arr[i];
                res = min(res, abs(target - arr[j]));
	    		if (arr[j] == arr[j + 1]) break;
            }
        }
        return res;
    }
};