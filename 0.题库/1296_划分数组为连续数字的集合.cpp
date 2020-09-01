/*************************************************************************
	> File Name: 1296_划分数组为连续数字的集合.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Aug 2020 12:01:26 AM CST
 ************************************************************************/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]] += 1;
        }

        for (map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second == 0) continue;
            int x = iter->second, y = iter->first;
            int j = 0;
            for (map<int, int>::iterator i = iter; i != m.end() && j < k; ++i, ++j) {
                if (j) {
                    if (i->first != y + 1) return false;
                    y =  i->first;
                }
                if (i->second < x) return false;
                i->second -= x;
            }
            if (j < k) return false;
        }
        return true;
    }
};
