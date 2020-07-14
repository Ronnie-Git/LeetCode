/*
 * 二分答案法
 */
int check(char *s, int len) {
    if (len == 0) return 1;
    int num[256] = {0}, cnt = 0;
    for (int i = 0; s[i]; i++) {
        num[s[i]] += 1;
        cnt += (num[s[i]] == 1);
        if (i >= len) {
            num[s[i - len]]--;
            cnt -= (num[s[i - len]] == 0);
        }
        if (cnt == len) return 1;
    }
    return 0;
}

int lengthOfLongestSubstring(char* s) {
    int head = 0, tail = strlen(s), mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (check(s, mid) == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

/*
 * 滑动窗口法、双指针法
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flags[256] = {0}, len = s.length(), cnt = 0, res = 0;
        for (int i = 0; i < len; ++i) {
            if (flags[s[i]]) {
                while (flags[s[i]]) flags[s[i - cnt]] = 0, --cnt;
            }
            ++cnt;
            if (cnt > res) res = cnt;
            flags[s[i]] = 1;
        }
        return res;
    }
};