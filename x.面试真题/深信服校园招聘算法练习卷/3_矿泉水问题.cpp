#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, a, b, t;
    cin >> t;
    while (t--) {
        cin >> x >> a >> b;
        int k = b / a, res = 0;
        if (k >= 3) {
            int m = x % 500;
            res = x / 500 * a;
            if (m > 0) res += a;
        } else {
            int m = x % 1500;
            res = x / 1500 * b;
            if (m > 0) {
                if (m > 1000) res += b;
                else if (m > 500) {
                    if (b < 2 * a) res += b;
                    else res += a + a;
                } else {
                    if (b < a) res += b;
                    else res += a;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}