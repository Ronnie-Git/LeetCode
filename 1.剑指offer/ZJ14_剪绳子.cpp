class Solution {
public:
    int cuttingRope(int n) {
    	if (n < 3) return 1;
        if (n == 3) return 2;
    	int a = n % 3, b = n / 3;
    	if (a == 0) return pow(3, b);
    	else if (a == 2) return pow(3, b) * 2;
    	else return pow(3, b - 1) * 2 * 2;
    }
};