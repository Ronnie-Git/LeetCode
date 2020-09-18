/*************************************************************************
	> File Name: 338_比特位计数.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Sep 2020 06:09:15 PM CST
 ************************************************************************/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i) {
            int x = 0, temp = i;
            while (temp) {
                ++x;
                temp &= (temp - 1);
            }
            res[i] = x;
        }
        return res;
    }
};
