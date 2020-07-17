class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 0, res = 0, len_word = wordList.size();
        while (cnt < wordList.size() && wordList[cnt] != endWord) ++cnt;
        if (cnt >= wordList.size()) return false;

        unordered_set<string> inbegin, inend; // 标记是否已经访问过
        queue<string> qbegin, qend; // 双向广搜的辅助队列

        qbegin.push(beginWord), qend.push(endWord);
        inbegin.insert(beginWord), inend.insert(endWord);
    	while (!qbegin.empty() && !qend.empty()) { // 有一个方向结束就终止搜索
    		res += 1;
    		int lenb = qbegin.size(), lene = qend.size();
    		// 优先搜索队列元素少的
    		if (lenb <= lene) { // 从上到下
    			while (lenb--) {
    				string temp = qbegin.front();
    				qbegin.pop();
    				for (int i = 0; i < len_word; ++i) {
    					// 如果已经访问过或者无法转换，则进行下一次循环
    					if (inbegin.find(wordList[i]) != inbegin.end() || !check(temp, wordList[i])) continue; 
    					
    					if (inend.find(wordList[i]) != inend.end()) return res + 1; // 如果另一个方向已搜索过则直接return
    					qbegin.push(wordList[i]);
    					inbegin.insert(wordList[i]);
    				}
    			}
    		} else { // 从下到上
    			while (lene--) {
    				string temp = qend.front();
    				qend.pop();
    				for (int i = len_word - 1; i >= 0; --i) {
    					if (inend.find(wordList[i]) != inend.end() || !check(temp, wordList[i])) continue;
    					if (inbegin.find(wordList[i]) != inbegin.end()) return res + 1;
    					qend.push(wordList[i]);
    					inend.insert(wordList[i]);
    				}
    			}
    		}
    	}

    	// 到此说明没有找到
    	return 0;
    }

    bool check(string &a, string &b) {
    	if (a.size() != b.size()) return false;
   		int cnt = 0;
    	for (int i = 0; i < a.size(); ++i) {
    		if (a[i] != b[i]) ++cnt;
    	}
    	return cnt == 1;
    }
};