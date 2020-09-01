/*************************************************************************
	> File Name: 93_复原IP地址.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Aug 2020 08:12:34 PM CST
 ************************************************************************/

class Solution {
public:
    void helper(string &s, int i, vector<string> &res, string temp, int cnt) {
        int len = s.size();
        if (cnt == 4) {
            //cout << temp << endl;
           if (i == len) {
               temp.pop_back();
               res.push_back(temp);
           }
           return ; 
        }
        if (i == len) return ;
        helper(s, i + 1, res, temp + s[i] + '.', cnt + 1);
        if (i + 1 < len) {
            if (s[i] != '0')
                helper(s, i + 2, res, temp + s[i] + s[i + 1] + '.', cnt + 1);
        }
        if (i + 2 < len) {
            if (s[i] != '0' && s.substr(i, 3) <= "255") 
                helper(s, i + 3, res, temp + s[i] + s[i + 1] + s[i + 2] + '.', cnt + 1);
        }
        return ;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, 0, res, "", 0);
        return res;
    }
};
