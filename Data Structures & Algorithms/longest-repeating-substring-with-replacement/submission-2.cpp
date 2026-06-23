class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;
                int maxFreq = *max_element(freq, freq + 26);
                int windowSize = j - i + 1;

                if (windowSize - maxFreq <= k) {
                    ans = max(ans, windowSize);
                }
            }
        }

        return ans;
    }
};