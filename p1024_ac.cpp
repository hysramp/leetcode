class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        uint32_t maxEnd[T + 1];
        uint32_t minStart[T + 1];
        memset(maxEnd, 0, sizeof(uint32_t) * (T + 1));
        memset(minStart, 0xFFFFFFFF, sizeof(uint32_t) * (T + 1));
        
        for (size_t i = 0; i < clips.size(); ++i) {
            
            if (clips[i][0] > T || clips[i][1] < 0) {
                continue;
            }
            
            clips[i][0] = clips[i][0] < 0 ? 0 : clips[i][0];
            clips[i][1] = clips[i][1] > T ? T : clips[i][1];
            
            if (maxEnd[clips[i][0]] < clips[i][1]) {
                maxEnd[clips[i][0]] = clips[i][1];
            }
            
            if (minStart[clips[i][1]] > (uint32_t)clips[i][0]) {
                minStart[clips[i][1]] = (uint32_t)clips[i][0];
            }
        }
        
        uint32_t dp[T + 1];
        memset(dp, 0, sizeof(uint32_t) * (T + 1));
        
        queue<pair<uint32_t, uint32_t>> q;
        for (uint32_t i = 0; i <= T; ++i) {
            if (maxEnd[i] > 0 && (q.empty() || maxEnd[i] > q.front().second)) {
                q.push(pair<uint32_t, uint32_t>(i, maxEnd[i]));
            }
            
            while(q.size() > 0 && q.front().second < i) {
                q.pop();
            }
            
            if (q.empty()) {
                return -1;
            }
            
            dp[i] = q.front().first == 0 ? 1 : dp[q.front().first] + 1;
        }
        
        return dp[T];
    }
};
