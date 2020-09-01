/*************************************************************************
	> File Name: 49_字母异位词分组.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Aug 2020 08:51:34 PM CST
 ************************************************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > m;
        int len = strs.size();
        for (int i = 0; i < len; ++i) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        for (auto &x : m) {
            res.push_back(x.second);
        }
        
        return res;
    }
};
