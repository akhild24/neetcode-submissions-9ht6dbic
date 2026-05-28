class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0;
        int R = heights.size() - 1;
        int ans = 0;

        while (L < R) {
            int width = R - L;
            int height = min(heights[L], heights[R]);
            int water = width * height;
            ans = max(ans, water);

            
            if (heights[L] <= heights[R])
                L++;
            else
                R--;
        }

        return ans;
    }
};