/*************************************************************************
	> File Name: 10.01_合并排序的数组.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 09 Aug 2020 09:50:12 AM CST
 ************************************************************************/

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i = n - 1, j = m - 1, l = n + m - 1;
        while (i >= 0) {
            if (j < 0 || B[i] > A[j]) A[l--] = B[i--];
            else A[l--] = A[j--];
        }
        return ;
    }
};
