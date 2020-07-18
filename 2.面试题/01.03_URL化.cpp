/*************************************************************************
	> File Name: 01.03_URL化.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jul 2020 10:36:30 AM CST
 ************************************************************************/

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int cnt = S.size() - 1;
        for (int i = length - 1; i >= 0; --i) {
            if (S[i] == ' ') {
                S[cnt--] = '0';
                S[cnt--] = '2';
                S[cnt--] = '%';
            } else {
                S[cnt--] = S[i];
            }
        }
        return S.substr(cnt + 1, S.size() - cnt);
    }
};
