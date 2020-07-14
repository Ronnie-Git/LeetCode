class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, maxnum = 0;
        while (left < right) {
            maxnum = max(maxnum, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) ++left;
            else --right;
        }
        return maxnum;
    }
};