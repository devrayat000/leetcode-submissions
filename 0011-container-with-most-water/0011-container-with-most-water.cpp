class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            area = max(min(heights[l], heights[r]) * (r - l), area);
            if (heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return area;
    }
};
