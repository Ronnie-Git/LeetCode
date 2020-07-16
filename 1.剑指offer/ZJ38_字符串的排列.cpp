class Solution {
public:
    vector<string> permutation(string s) {
    	string temp = s;
        sort(temp.begin(), temp.end());
    	vector<string> res;
    	do {
    		res.push_back(temp);
    	} while(next_permutation(temp.begin(), temp.end()));
    	return res;
    }
};