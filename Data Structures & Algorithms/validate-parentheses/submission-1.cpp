class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            // Opening bracket → push
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            // Closing bracket
            else {
                // Stack empty → no matching opener
                if (st.empty()) return false;

                char top = st.top();

                if ((s[i] == ')' && top == '(') ||
                    (s[i] == '}' && top == '{') ||
                    (s[i] == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;  // Mismatched pair
                }
            }
        }

        // Unmatched openers still in stack
        if (!st.empty()) return false;

        return true;
    }
};