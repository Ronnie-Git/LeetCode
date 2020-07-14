class Solution {
public:
    int minArray(vector<int>& numbers) {
    	if (numbers.size() == 1 || numbers[0] < numbers[numbers.size() - 1]) return numbers[0];
    	int l = 0, r = numbers.size() - 1, mid;
    	while (l < r) {
    		mid = (l + r) >> 1;
    		if (numbers[mid] > numbers[r]) l = mid + 1;
    		else if (numbers[mid] < numbers[r]) r = mid;
            else r--;
    	}
    	return numbers[l];
    }
};