class Solution {
public:
    bool contains(unordered_map<char, int>& tFreq, string& s, int l, int r) {
        unordered_map<char, int> windowFreq;
        for (int i = l; i <= r; i++)
            windowFreq[s[i]]++;
        for (auto& [ch, cnt] : tFreq)
            if (windowFreq[ch] < cnt) return false;
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n == 0 || m == 0) return "";

        unordered_map<char, int> tFreq;
        for (char c : t) tFreq[c]++;

        int minLen = INT_MAX, resStart = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i + 1 >= m && contains(tFreq, s, i, j)) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        resStart = i;
                    }
                }
            }
        }

        return resStart == -1 ? "" : s.substr(resStart, minLen);
    }
};