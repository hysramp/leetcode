class Solution {
public:
    string removeOuterParentheses(string s) {
        uint32_t level = 0;
        string ans = "";
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                if (level > 0) ans += s[i];
                level++;
            }
            
            if (s[i] == ')') {
                level--;
                if (level > 0) ans += s[i];
            }
        }
        
        return ans;
    }
};
