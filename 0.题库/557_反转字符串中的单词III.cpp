/*************************************************************************
	> File Name: 557_反转字符串中的单词III.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Sep 2020 08:44:04 PM CST
 ************************************************************************/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j + 1 < n && s[j + 1] != ' ') ++j;
            int ind = j + 1;

            while (i < j) {
                swap(s[i], s[j]);
                ++i, --j;
            }

            i = ind;
        }

        return s;
    }
};
