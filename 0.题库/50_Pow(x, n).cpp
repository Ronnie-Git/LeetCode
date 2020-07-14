class Solution {
public:
    double _pow(double x, long long n) {
        if (n < 0) return 1.0 / _pow(x, -n);
        double res = 1.0;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    double myPow(double x, int n) {
        return _pow(x, n);
    }
};