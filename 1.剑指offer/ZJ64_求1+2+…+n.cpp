/*************************************************************************
	> File Name: ZJ64_求1+2+…+n.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 17 Jul 2020 02:45:43 PM CST
 ************************************************************************/

class Solution {
public:
    int sumNums(int n) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int b = i, c;
            while (b) {
                c = res ^ b;
                b = (unsigned int)(res & b) << 1;
                res = c;
            }
        }
        return res;
    }
};
