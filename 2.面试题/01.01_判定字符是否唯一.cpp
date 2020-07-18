/*************************************************************************
	> File Name: 01.01_判定字符是否唯一.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 07:17:47 PM CST
 ************************************************************************/

class Solution {
public:
    bool isUnique(string astr) {
        int flag = 0, cnt = 0;
        for (char x : astr) {
            int check = 1, cnt = x - 'a';
            if (flag & (check << cnt)) return false;
            flag |= (check << cnt);
        }
        return true;
    }
};
