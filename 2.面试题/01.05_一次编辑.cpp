/*************************************************************************
	> File Name: 01.05_一次编辑.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Jul 2020 06:19:13 PM CST
 ************************************************************************/

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int flen = first.size() - 1, slen = second.size() - 1;
        int i = 0, j = flen, l = slen;
        while (i <= slen && i <= flen && first[i] == second[i]) ++i;
        while (j >= 0 && l >= 0 && first[j] == second[l]) --j, --l;
        return i >= j && i >= l;
    }
};
