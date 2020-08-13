/*************************************************************************
	> File Name: 43_字符串相乘.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 13 Aug 2020 10:44:10 AM CST
 ************************************************************************/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 || num2.size() == 0) return "";
        if (num1[0] == '0' || num2[0] == '0') return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "";
        for (int i = 0; i < num1.size(); ++i) {
            int x = num1[i] - '0', y = 0, num = 0;
            for (int j = 0; j < num2.size(); ++j) {
                int temp = 0;
                if (i + j < ans.size()) {
                    temp = num + (ans[i + j] - '0') + (x * (num2[j] - '0'));
                    ans[i + j] = (temp % 10) + '0';
                } else {
                    temp = num + (x * (num2[j] - '0'));
                    ans += (temp % 10 + '0');
                }
                num = temp / 10;
            }
            if (num) ans += (num + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
