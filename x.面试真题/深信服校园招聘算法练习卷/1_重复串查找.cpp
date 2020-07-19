// 通过 80%

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int res = 0, len = s.size();
	for (int i = 0; i < len; ++i) {
		int cnt = i + res + 1;
		while (cnt < len && 2 * cnt - i <= len) {
			if (s[cnt] == s[i] && s[2 * cnt - i - 1] == s[cnt - 1])  {
				int l = i;
				for (int j = cnt; j < len && l < cnt; ++j, ++l) {
					if (s[l] != s[j]) break;
				}
				if (l == cnt) res = (cnt - i > res ? cnt - i : res);
			}
			++cnt;
		}
	}
	cout << res * 2 << endl;
}