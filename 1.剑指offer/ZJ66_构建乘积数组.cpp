/*************************************************************************
	> File Name: ZJ66_构建乘积数组.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 18 Jul 2020 05:09:31 PM CST
 ************************************************************************/


class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size());
        if (a.size() <= 0) return res;
        res[0] = 1;
        for (int i = 1; i < res.size(); ++i) res[i]  = res[i - 1] * a[i - 1];
        int temp = 1;
        for (int i = res.size() - 2; i >= 0; --i) {
            temp *= a[i + 1];
            res[i] *= temp;
        }
        return res;
    }
};
