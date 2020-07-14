class Solution {
public:
    bool check(string &stra, string &strb) {
        int count = 0;
        for (int i = 0; i < stra.size(); ++i) {
        	count += (stra[i] != strb[i]);
            if (count > 1) return false;
        }
        return count == 1;
    }

    void dfs(int i, vector<string>& wordList) {
        if (fa[i].empty()) {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
        }

        for (auto &x : fa[i]) {
            temp.push_back(wordList[x]);
            dfs(x, wordList);
            temp.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int b = -1, e = -1, x;
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == beginWord) b = i;
            if (wordList[i] == endWord) e = i;
        }
        if (e == -1) return ans;
        if (b == -1) wordList.push_back(beginWord), b = wordList.size() - 1;

        queue<int> que;
        fa.assign(wordList.size(), vector<int>());
        vector<int> index(wordList.size(), 0); // index代表第几层
        que.push(b), index[b] = 1;
        while (!que.empty()) {
            x = que.front(), que.pop();
            if (index[e] && index[x] >= index[e]) break;

            for (int i = 0; i < wordList.size(); ++i) {
                if ((index[i] == 0 || index[x] + 1 == index[i]) && check(wordList[x], wordList[i])) {
                    if (index[i] == 0) index[i] = index[x] + 1, que.push(i), fa[i].push_back(x);
                    else fa[i].push_back(x);
                }
            }
        }
        if (index[e] == 0) return ans;
        temp.push_back(endWord);
        dfs(e, wordList);
        temp.pop_back();

        return ans;
    }
private:
	vector<vector<string>> ans;
	vector<vector<int>> fa; // fa[1]有元素x，代表wordList[1]由wordList[x]转化过来
    vector<string> temp;   
};