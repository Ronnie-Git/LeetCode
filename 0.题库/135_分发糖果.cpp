/*************************************************************************
	> File Name: 135_分发糖果.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Sep 2020 04:34:13 PM CST
 ************************************************************************/

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> arr(ratings.size() + 5);
        int sum = 0;
        arr[0] = 1;
        for (int i = 0; i < ratings.size() - 1; ++i) {
            arr[i + 1] = 1;
            if (ratings[i + 1] > ratings[i]) {
                arr[i + 1] = arr[i] + 1;
            }
        }

        for (int i = ratings.size() - 1; i > 0; --i) {
            if (ratings[i - 1] > ratings[i]) {
                arr[i - 1] = max(arr[i - 1], arr[i] + 1);
            }
            sum += arr[i];
        }
        sum += arr[0];
        return sum;
    }
};
