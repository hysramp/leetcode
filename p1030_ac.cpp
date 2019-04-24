class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int dist = 0;
        vector<vector<int>> ans;
        while(true) {
            bool found = false;
            for (int d = -dist; d <= dist; ++d) {
                int r = r0 + d;
                int left = dist - abs(d);
                int c = c0 + left;
                if (r >= 0 && c >= 0 && r < R && c < C) {
                    found = true;
                    ans.push_back(vector<int>{r, c});
                }
                
                if (left) {
                    c = c0 - left;
                    if (r >= 0 && c >= 0 && r < R && c < C) {
                        found = true;
                        ans.push_back(vector<int>{r, c});
                    }
                }
            }
            
            dist++;
            
            if (!found) {
                break;
            }
        }
        
        return ans;
    }
};
