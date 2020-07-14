class Solution {
public:
    string reverseWords(string str) {
        stack<string> s;
        string temp = "";
        int i = 0;
        for (i = 0; i < str.size(); ++i) if (str[i] != ' ') break;
        for (;i < str.size(); ++i) {
            if (str[i] == ' ') {
                if (temp.size()) { s.push(temp); temp = ""; }
                if (!s.empty() && s.top() != " ") s.push(" ");
            } else {
                temp += str[i];
            }
        }
        if (temp.size()) { s.push(temp); temp = ""; }
        while (!s.empty() && s.top() == " ") s.pop();
        while (!s.empty()) {
            temp += s.top();
            s.pop();
        }
        return temp;
    }
};