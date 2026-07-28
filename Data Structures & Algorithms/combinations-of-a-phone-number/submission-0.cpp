class Solution {
public:
    unordered_map<char, string> f;  // moved to class scope so fun() can access it

    void fun(string &s, int n, int idx, string diary, vector<string> &res) {
        if(idx == n) {  // x → n
            res.push_back(diary);
            return;
        }
        string choice = f[s[idx]];
        for(int j=0; j<choice.size(); j++) {
            diary.push_back(choice[j]);
            fun(s, n, idx+1, diary, res);
            diary.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        if(digits.empty()) return {};  // edge case LC expects

        int n = digits.size();  // s → digits
        string diary = "";
        vector<string> res;

        fun(digits, n, 0, diary, res);  // fixed args

        return res;
    }
};