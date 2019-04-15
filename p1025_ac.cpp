class Solution {
public:
    bool divisorGame(int N) {
        bool ans[1001];
        memset(ans, 0, sizeof(bool) * 1001);
        ans[0] = false;
        ans[1] = false;
        ans[2] = true;
        ans[3] = false;
        
        for (int n = 4; n <= N; ++n) {
            for (int x = 1; x < n; ++x) {
                if (n % x == 0 && ans[n - x] == false) {
                    ans[n] = true;
                    break;
                }
            }
        }
        
        return ans[N];
    }
};
