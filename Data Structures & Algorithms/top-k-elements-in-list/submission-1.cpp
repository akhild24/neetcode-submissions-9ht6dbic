class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int num: nums){
            freq[num]++;
        }
        int n= nums.size();
        vector<vector<int>>buckets(n+1);
        for (auto it: freq){
        int number = it.first;
        int frequency= it.second;
        buckets[frequency].push_back(number);
        }
         vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }
        return result;
    }

};
