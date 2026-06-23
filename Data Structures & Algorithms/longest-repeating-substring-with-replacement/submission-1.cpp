class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;

        // try every possible window [i, j]
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};  // reset for every new start
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'A']++;

                // find most frequent char in current window
                int maxFreq = *max_element(freq, freq + 26);

                int windowSize = j - i + 1;
                int replacementsNeeded = windowSize - maxFreq;

                if (replacementsNeeded <= k) {
                    ans = max(ans, windowSize);
                }
                // if > k, this window is invalid but keep going
                // (a bigger j might not help, but we still check all)
            }
        }

        return ans;
    }
};