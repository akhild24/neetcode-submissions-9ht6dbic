class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            // only start count if it's the beginning of a sequence
            if (st.find(nums[i] - 1) == st.end()) {
                int current = nums[i];
                int count = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};