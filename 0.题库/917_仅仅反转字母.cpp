/*************************************************************************
	> File Name: 917_仅仅反转字母.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jul 2020 09:03:09 PM CST
 ************************************************************************/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size() - 1;
        while (l < r) {
            if (!check(S[r])) { --r; continue; }
            if (!check(S[l])) { ++l; continue; }
            char tmp = S[l]; S[l] = S[r]; S[r] = tmp;
            ++l, --r; 
        }
        return S; 
    }

    bool check(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
};
