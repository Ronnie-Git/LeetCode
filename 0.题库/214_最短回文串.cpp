/*************************************************************************
	> File Name: 214_最短回文串.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Aug 2020 08:17:54 PM CST
 ************************************************************************/

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size(), j = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == s[j]) ++j;
        }
        if (j == n) return s;
        string temp = s.substr(j, n);
        reverse(temp.begin(), temp.end());
        return temp + shortestPalindrome(s.substr(0, j)) + s.substr(j, n);
    }
}; 
