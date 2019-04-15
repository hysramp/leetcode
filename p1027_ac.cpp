class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        size_t N = A.size();
        int ans = 1;
        
        map<int, int> data[N];
        
        for (size_t i = 1; i < N; ++i) {
            data[i].clear();
            for (size_t j = 0; j < i; ++j) {
                int diff = A[i] - A[j];
                
                int len = 2;
                map<int, int>::iterator itr = data[j].find(diff);
                if (itr != data[j].end()) {
                    len = itr->second + 1;
                }
                
                ans = len > ans ? len : ans;
                
                itr = data[i].find(diff);
                if (itr != data[i].end()) {
                    itr->second = len > itr->second ? len : itr->second;
                } else {
                    data[i][diff] = len;
                }
            }
        }
        return ans;
    }
};
