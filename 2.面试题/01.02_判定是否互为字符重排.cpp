/*************************************************************************
	> File Name: 01.02_判定是否互为字符重排.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jul 2020 08:44:47 AM CST
 ************************************************************************/


class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int flags[26] = {0};
        for (int i = 0; i < s1.length(); ++i) {
            ++flags[s1[i] - 'a'];
            --flags[s2[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (flags[i] != 0) return false;
        }
        return true;
    }
};

