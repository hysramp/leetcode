class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = 0;
        vector<bool> ans;
        for (size_t i = 0; i < A.size(); ++i) {
            n = ((n << 1) + A[i]) % 10;
            ans.push_back(n % 5 == 0);
        }
        
        return ans;
    }
};
