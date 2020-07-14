class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
    	long long int a = 0, b = 1, temp, mod = 1e9 + 7;
    	while (n-- >= 2) {
    		temp = (a + b) % mod;
    		a = b;
            b = temp;
    	}
    	return temp;
    }
};