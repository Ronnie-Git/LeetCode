/*************************************************************************
	> File Name: 67_二进制求和.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 17 Sep 2020 05:12:05 PM CST
 ************************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, num = 0;
        while (i >= 0 || j >= 0) {
            if (i < 0) {
                num += (b[j--] - '0');
            } else if (j < 0) {
                num += (a[i--] - '0');
            } else {
                num += (b[j--] - '0') + (a[i--] - '0');
            }
            char ch = (num & 1) + '0';
            res = res + ch;
            num >>= 1;
        }
        if (num) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
