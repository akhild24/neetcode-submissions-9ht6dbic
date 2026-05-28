class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans =0; 
        int L = 0; 
        int R = heights.size()-1; 

        while (L<R){
            int width = R -L;
            int height = min(heights[L], heights[R]);
            int water = width * height; 
            ans = max(ans, water);

            if (heights[L]<= heights[R])
            L++;
            else 
            R--;
        }
        return ans;
    }
};
