/*************************************************************************
	> File Name: ZJ46_把数字翻译成字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jul 2020 01:55:26 PM CST
 ************************************************************************/

class Solution {
public:
    int translateNum(int num) {
        int now = 1, last = 1;
        string s = to_string(num);
        for (int i = 2; i <= s.size(); ++i) {
            int temp = now;
            if (s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 25)) now += last;
            last = temp;
        }
        return now;
    }
};
