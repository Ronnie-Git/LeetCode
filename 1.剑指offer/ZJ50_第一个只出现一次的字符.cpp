class Solution {
public:
    char firstUniqChar(string s) {
    	int flags[256] = {0};
    	for (int i = 0; i < s.length(); ++i) {
    		if (!flags[s[i]]) flags[s[i]] = 1;
    		else flags[s[i]] = -1;
    	}
    	for (int i = 0; i < s.length(); ++i) {
            cout << s[i] << " " << flags[s[i]] << endl;
    		if (flags[s[i]] == -1) return s[i]; 
    	}
    	return ' ';
    }
};