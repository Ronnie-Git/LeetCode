/*************************************************************************
	> File Name: ZJ43_1～n整数中1出现的次数.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Jul 2020 09:33:56 AM CST
 ************************************************************************/

class Solution {
public:
    int countDigitOne(int n) {
        long long int h = n / 10, m = n % 10, l = 0, digit = 1, res = 0;
        while (h || m) {
            if (m == 0) res += h * digit;
            else if (m == 1) res += h * digit + l + 1;
            else res += (h + 1) * digit;
            l = m * digit + l;
            m = h % 10;
            h /= 10;
            digit *= 10;
        }
        return res;
    }
};
