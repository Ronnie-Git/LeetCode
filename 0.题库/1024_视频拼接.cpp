/*************************************************************************
	> File Name: 1024_视频拼接.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 21 Jul 2020 05:51:28 PM CST
 ************************************************************************/

class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0];
    }
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), cmp);
        int res = 1;
        int s = clips[0][0], e = clips[0][1];
        if (s != 0) return -1;
        for (int i = 1; i < clips.size(); ++i) {
            if (e >= T) return res;
            if (e < clips[i][0]) return -1;
            if (e >= clips[i][1]) continue;
            if (clips[i][0] <= s && clips[i][1] >= e) {
                e = clips[i][1];
                continue;
            }
            if (clips[i][1] > e) {
                s = (e > clips[i][0] ? e : clips[i][0]);
                e = clips[i][1];
                res += 1;
            }
        }
        if (e < T) return -1;
        return res;
    }
};
