/*************************************************************************
	> File Name: 394_字符串解码.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Aug 2020 11:35:25 PM CST
 ************************************************************************/

class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        string temp = "";
        int num = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '[') {
                nums.push(num);
                num = 0;
                str.push(temp);
                temp = "";
            } else if (s[i] == ']') {
                int len = nums.top();
                nums.pop();
                for (int i = 0; i < len; ++i) {
                    str.top() += temp;
                }
                temp = str.top();
                str.pop();
            } else if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else {
                temp += s[i];
            }
        }
        return temp;
    }
};
