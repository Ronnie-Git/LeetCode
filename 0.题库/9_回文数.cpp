/*************************************************************************
	> File Name: 9_回文数.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 18 Aug 2020 11:03:02 PM CST
 ************************************************************************/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long y = 0, t = x;
        while (t) {
            y = y * 10 + t % 10;
            t /= 10;
        }
        return x == y;
    }
};
