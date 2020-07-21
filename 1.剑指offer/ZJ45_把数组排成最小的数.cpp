/*************************************************************************
	> File Name: ZJ45_把数组排成最小的数.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 03:50:45 PM CST
 ************************************************************************/

class Solution {
public:
    void quick_sort(vector<string> &strs, int l, int r) {
        if(l >= r) return;
        int i = l, j = r;
        string tmp = strs[i];
        while(i < j) {
            while(i < j && strs[j] + strs[l] >= strs[l] + strs[j]) j--;
            while(i < j && strs[i] + strs[l] <= strs[l] + strs[i]) i++;
            tmp = strs[i];
            strs[i] = strs[j];
            strs[j] = tmp;
        }
        strs[i] = strs[l];
        strs[l] = tmp;
        quick_sort(strs, l, i - 1);
        quick_sort(strs, i + 1, r);
        return ;
    }

    string minNumber(vector<int>& nums) {
        string res = "";
        vector<string> str(nums.size());
        for (int i = 0; i < nums.size(); ++i) str.push_back(to_string(nums[i]));
        quick_sort(str, 0, str.size() - 1);
        for (int i = 0; i < str.size(); ++i) res += str[i];
        return res;
    }
};
