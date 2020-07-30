/*************************************************************************
	> File Name: 01.06_字符串压缩.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Jul 2020 06:44:24 PM CST
 ************************************************************************/

class Solution {
public:
    string compressString(string S) {
        if (S.size() == 0) return S;
        int cnt = 1, len = S.size();
        string res = "";
        res += S[0];
        for (int i = 1; i < len; ++i) {
            if (S[i] != S[i - 1]){
                res += to_string(cnt);
                res += S[i];
                cnt = 1;
            } else {
                cnt += 1;
            }
        }
        if (cnt) res += to_string(cnt);
        return res.size() >= len ? S : res;
    }
};
