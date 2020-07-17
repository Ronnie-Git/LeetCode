/*************************************************************************
	> File Name: ZJ20_表示数值的字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 10:11:52 AM CST
 ************************************************************************/

class Solution {
public:
    bool isNumber(string s) {
        if (s.sise() == 0) return false;
        if (s.size() == 1 && (s[0] < '0' || s[0] > '9')) return false;

        int starti = 0, endi = s.size(), dcnt = 0, ecnt = 0, pcnt = 0;
        if (s[0] == '-' || s[0] == '+') ++starti;
        for (int i = starti; i < endi; ++i) {
            if (s[i] >= '0' && s[i] <= '9') continue;
            if (s[i] == '.') {
                if (i == starti || pcnt || ecnt) return false;
                pcnt = 1;
            }
            if (s[i] == 'e') {
                if (i != istart + 1 || i + 1 >= endi || pcnt || ecnt) return false;
                if (s[i + 1] >= '0' || s[i + 1] <= '9') continue;
                if (s[i + 1] != '-' || i + 2 >= endi || s[i + 2] <= '0' || s[i + 2] >= '9') return false;
                i += 1;
            } else {
                return false;
            }
        }
        return true;
    }
};
