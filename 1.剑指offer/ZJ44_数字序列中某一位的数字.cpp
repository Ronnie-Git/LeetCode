/*************************************************************************
	> File Name: ZJ44_数字序列中某一位的数字.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Jul 2020 10:02:21 AM CST
 ************************************************************************/

class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        n -= 9;
        long long int base = 10, i = 2;
        while (n > base * 9 * i) {
            n -= base * 9 * i;
            base *= 10;
            i += 1;
        }
        long long int h = base + n / i - 1, k = n % i;
        if (k == 0) return h % 10; // 结果是h的末尾
        return (h + 1) / (int)pow(10, i - k) % 10; // 结果是 h + 1 中的第 k 位
         
    }
};
