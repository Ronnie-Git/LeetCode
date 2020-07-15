class Solution {
public:
    double _quickPow(double x, long long n) {
        if (n < 0) return 1.0 / _quickPow(x, -n);
    	double res = 1.0;
    	while (n) {
    		if (n & 1) res = res * x;
    		x *= x;
    		n >>= 1;
    	}
    	return res;
    }

    double myPow(double x, int n) {
        return _quickPow(x, n);
    }
};