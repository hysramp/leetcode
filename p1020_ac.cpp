class Solution {
private:
    uint32_t n, m;
    vector<vector<int>> *A;
    int32_t dir[5] = {1, 0, -1, 0, 1};
    uint32_t dfs(int32_t x, int32_t y) {
        uint32_t ret = 1;
        (*A)[x][y] = 2;
        
        for (size_t d = 0; d < 4; ++d) {
            int32_t xx = x + dir[d];
            int32_t yy = y + dir[d + 1];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
                ret = 0;
                continue;
            }
            
            if ((*A)[xx][yy] == 1) {
                uint32_t rest = dfs(xx, yy);
                ret = ret == 0 || rest == 0 ? 0 : ret + rest;
            }
        }
        
        return ret;
    }
public:
    int numEnclaves(vector<vector<int>>& A) {
        int ans = 0;
        this->A = &A;
        n = A.size();
        if (n <= 0) { return ans; }
        m = A[0].size();
        
        for (size_t x = 0; x < n; ++x) {
            for (size_t y = 0; y < m; ++y) {
                if (A[x][y] == 1)
                    ans += dfs(x, y);
            }
        }
        
        return ans;
    }
};
