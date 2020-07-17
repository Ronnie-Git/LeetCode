/*************************************************************************
	> File Name: ZJ67_把字符串转换成整数.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 02:34:25 PM CST
 ************************************************************************/

class Solution {
public:
    int strToInt(string str) {
        long long num = 0, flag = 1;
        int starti = 0, len = str.length(); 
        for (int i = starti; i < len; ++i) {
            if (str[i] != ' ') break;
            ++starti;
        }
        if (starti >= len) return 0;
        if (str[starti] == '-' || str[starti] == '+') {
            if (str[starti] == '-') flag = -1;
            ++starti;
        }
        for (int i = starti; i < len; i++) {
            if (str[i] < '0' || str[i] > '9') break;
            num = num * 10 + (str[i] - '0');
            if (flag == 1 && num > INT_MAX) return INT_MAX;
            if (flag == -1 && -num < INT_MIN) return INT_MIN;
        }
        return (int)num * flag;
    }
};
