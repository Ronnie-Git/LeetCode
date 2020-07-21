/*************************************************************************
	> File Name: ZJ60_n个骰子的点数.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 10:01:15 AM CST
 ************************************************************************/

class Solution {
public:
    vector<double> twoSum(int n) {
        int cnt = n * 6 - n + 1; // 求得有多少种可能点数和
        vector<double> res(cnt, 0);
        for (int i = 0; i < 6; ++i) res[i] = 1;
        // 滚动数组
        for (int i = 2; i <= n; ++i) {
            for (int j = i * 6 - i; j >= 0; --j) { // 采用滚动数组，所以倒着搜
                for (int l = 1; l < 6 && j - l >= 0; ++l) { 
                    // 当前的状态可以由n-1个骰子的 dp(n-1, j-1) + ... + dp(n-1, j-6)，相加得到
                    // 因为当前增加了一个骰子，所以所有骰子最少和由n-1变为n，即res[j]的值就是dp(n-1, j-1)
                    res[j] += res[j - l];
                }
            }
        }
        
        for (int i = 0; i < cnt; ++i) {
            res[i] = res[i] * (1.0 / pow(6, n));
        }
        return res;
    }
};
