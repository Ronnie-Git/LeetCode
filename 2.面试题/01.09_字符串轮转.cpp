/*************************************************************************
	> File Name: 01.09_字符串轮转.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Aug 2020 09:25:27 AM CST
 ************************************************************************/

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0) return true;
        // 方法一
        // return (s2 + s2).find(s1) != string::npos;

        // 方法二
        string temp = s2 + s2;
        int tempSize = temp.size(), sSize = s1.size();
        int j = -1;

        int next[100005] = {0};
        next[0] = -1;
        for (int i = 1; i < sSize; ++i) {
            j = next[i - 1];
            while (j != -1 && s1[i] != s1[j + 1]) j = next[j];
            if (s1[i] == s1[j + 1]) next[i] = j + 1;
            else next[i] = -1;
        }

        j = -1;
        for (int i = 0; i < tempSize; ++i) {
            while (j != -1 && temp[i] != s1[j + 1]) j = next[j];
            if (temp[i] == s1[j + 1]) ++j;
            if (j + 1 == s1.size()) return true;
        }
        return false;
    }
};
