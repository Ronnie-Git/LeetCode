class Solution {
public:
	long long quick_pow(long long a, long long b, long long c) {
		long long res = c, mod = 1e9 + 7;
		while (b) {
			if (b & 1) res = res * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return res % mod;
	}
    int cuttingRope(int n) {
    	if (n < 3) return 1;
        if (n == 3) return 2;
    	int a = n % 3, b = n / 3;
    	if (a == 0) return (int)quick_pow(3, b, 1);
    	else if (a == 2) return (int)quick_pow(3, b, 2);
    	else return (int)quick_pow(3, b - 1, 4);
    }
};