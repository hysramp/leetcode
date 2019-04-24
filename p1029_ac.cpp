class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] - a[1] < b[0] - b[1];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), Solution::cmp);
        
        int sum = 0;
        for (int i = 0; i < costs.size(); ++i) {
            sum += i * 2 < costs.size() ? costs[i][0] : costs[i][1];
        }
        
        return sum;
    }
};
