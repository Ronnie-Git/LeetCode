/*
 * 从后往前扫，遇到 % 判断是否能替换，如果能提换，继续判断当前字符，以为有可能被替换为 %
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void init(int *num) {
	memset(num, -1, sizeof(num));
	for (char i = '0'; i <= '9'; ++i) num[i] = i - '0';
	for (char i = 'a'; i <= 'f'; ++i) num[i] = (i - 'a') + 10;
	for (char i = 'A'; i <= 'F'; ++i) num[i] = (i - 'A') + 10;
	return ;
}

int check(char a, char b, int *num) {
	return num[a - 0] * 16 + num[b - 0];
}

int main() {
	int t;
	int num[300] = {0};
	init(num);

	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int i = s.size() - 1;
		while (i >= 0) {
			if (s[i] != '%' || i + 2 >= s.size()) { i -= 1; continue; }
			
			int ch = check(s[i + 1], s[i + 2], num);
			if (ch >= 0) {
				s.erase(i + 1, 2);
				s[i] = ch;
			} else {
				i -= 1;
			}
		}
		cout << s << endl;
	}
	return 0;
}