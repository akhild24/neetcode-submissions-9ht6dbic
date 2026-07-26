class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(vector<int>& nums, int target, int total, int start) {
        if(total == target) {
            result.push_back(current);
            return;
        }
        if(total > target) return;

        for(int i=start; i<nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, target, total+nums[i], i);   // i, not i+1
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, target, 0, 0);
        return result;
    }
};