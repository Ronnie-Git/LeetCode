class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
    	int i = num1.length() - 1, j = num2.length() - 1, temp = 0;
    	while (i >= 0 || j >= 0) {
    		if (i < 0) {
                temp = temp + (num2[j] - '0');
            } else if (j < 0) {
                temp = temp + (num1[i] - '0');
    		} else {
                temp = temp + (num1[i] - '0') + (num2[j] - '0');
            }
    		res += (temp % 10 + '0');
    		temp /= 10;
            --i, --j;
    	}
    	while (temp) {
    		res += (temp % 10 + '0');
    		temp /= 10;
    	}
        reverse(res.begin(), res.end());
        return res;
    }
};