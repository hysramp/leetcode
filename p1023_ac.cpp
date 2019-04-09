class Solution {
    
private:
    bool isMatch(string& query, string& pattern) {
        size_t pIndex = 0;
        for (size_t i = 0; i < query.length(); ++i) {
            if (query[i] >= 'a' && query[i] <= 'z') {
                if (pIndex < pattern.length() && query[i] == pattern[pIndex]) {
                    pIndex++;
                }
                
                continue;
            } else {
                if (pIndex >= pattern.length()) {
                    return false;
                }
                
                if (query[i] != pattern[pIndex]) {
                    return false;
                }
                
                pIndex ++;
            }
        }
        
        return pIndex == pattern.length();
    }
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (size_t i = 0; i < queries.size(); ++i) {
            ans.push_back(isMatch(queries[i], pattern));
        }
        
        return ans;
    }
};
