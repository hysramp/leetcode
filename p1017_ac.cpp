class Solution {
    
private:
    int findMaxPos(int& n) {
        long long s = n > 0 ? 1 : -2;
        int pos = n > 0 ? 0 : 1;
        long long sum = s;
        while(abs(sum) < abs((long long)n)) {
            s = s * 4;
            sum = sum + s;
            pos+= 2;
        }
        
        n = n - s;
        return pos;
    }
public:
    string baseNeg2(int N) {
        string ans = "0";
        
        while(N != 0) {
            int pos = findMaxPos(N);
            while (ans.length() <= pos) {
                ans = ans + "0";
            }
            
            ans[pos] = '1';
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
