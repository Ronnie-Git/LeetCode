class Solution {
public:
    int numWays(int n) {
        if (n == 0) return 1;
        if (n <= 2) return n;
        int a = 1, b = 2, res = 0, mod = 1e9 + 7;
        while (n-- >= 3) {
        	res = (a + b) % mod;
        	a = b;
        	b = res;
        }
        return res;
    }
};