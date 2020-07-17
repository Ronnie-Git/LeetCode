/*************************************************************************
	> File Name: ZJ58-II.左旋转字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 09:59:55 AM CST
 ************************************************************************/

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (n <= 0) return s;
        int i = 0; 
        s.append(s, 0, n);
        return s.substr(n, s.length() - n);
    }
};
