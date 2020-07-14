// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (r - l) / 2 + l;
            int k = guess(mid);
            if (!k) return mid;
            if (k == 1) l = mid + 1;
            else r = mid - 1;
        }
        return 0;
    }
};