/*************************************************************************
	> File Name: ZJ48_最长不含重复字符的子字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 30 Jul 2020 10:31:52 AM CST
 ************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int count[256] = {0};
        memset(count, -1, sizeof(count));
        count[s[0]] = 0;

        int j = 0, res = 1, len = s.size();
        for (int i = 1; i < len; ++i) {
            if (count[s[i]] == -1) {
                res = (res > (i - j + 1) ? res : (i - j + 1));
            } else {
                while (j <= count[s[i]]) count[s[j++]] = -1;
            }
            count[s[i]] = i;
        }
        return res;
    }
};
