class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map; // sorted_word → [anagrams]

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sort a copy, not original
            map[key].push_back(s);        // group by sorted key
        }

        vector<vector<string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }
};