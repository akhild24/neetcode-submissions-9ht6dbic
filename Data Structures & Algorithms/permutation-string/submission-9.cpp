class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int freq1[26] = {}, freq2[26] = {};
        int k = s1.size();

        for (int i = 0; i < k; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        auto match = [&]() {
            for (int i = 0; i < 26; i++)
                if (freq1[i] != freq2[i]) return false;
            return true;
        };

        if (match()) return true;

        for (int i = k; i < (int)s2.size(); i++) {
            freq2[s2[i] - 'a']++;
            freq2[s2[i - k] - 'a']--;
            if (match()) return true;
        }

        return false;
    }
};