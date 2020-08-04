/*
https://leetcode.com/contest/weekly-contest-200/problems/find-the-winner-of-an-array-game/

这个问题要想清楚，避免想得过于复杂
他不是一定要 arr0 赢了 arr1 才加 winning score， arr1赢了也会加
如果k大于 arr.size() 无所谓，因为winner 一定有的， 也就是说，arr.size() 过一遍，winner 已经决定了
k 如果是极大数 > arr.size()， 并且winner一定存在， 那基本代表这个winner 就是过一遍留下来的那个数（arr 里最大的数） 
k 如果小于 arr.size()， 过一遍早就找到了
这就是为啥答案是很简单的

*/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cur = arr[0], cw = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > cur) {
                cur = arr[i];
                cw = 0;
            }
            if (++cw == k) break ;
        }
        return cur;
    }
};