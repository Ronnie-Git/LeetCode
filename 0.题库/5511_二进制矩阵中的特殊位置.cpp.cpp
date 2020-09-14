/*************************************************************************
	> File Name: 5511_二进制矩阵中的特殊位置.cpp.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Sep 2020 06:41:24 PM CST
 ************************************************************************/


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> r(mat.size()), c(mat[0].size());
        int x = 0, y = 0;
        int rlen = mat.size(), clen = mat[0].size();
        for (int i = 0; i < rlen; ++i) {
            for (int j = 0; j < clen; ++j) {
                if (mat[i][j] == 1) r[i] += 1, c[j] += 1;
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < rlen; ++i) {
            if (r[i] != 1) continue;
            for (int j = 0; j < clen; ++j) {
                if (mat[i][j] == 1 && c[j] == 1) {
                    cnt++;
                    c[j] = 0;
                } 
            }
        }
        return cnt;
    }
};
