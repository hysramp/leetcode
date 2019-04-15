/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int nextD;
    int nextV;
    int pos;
    string* s;
    
    bool moveNext() {
        if (pos >= s->length()) {
            nextD = -1;
            return false;
        }
        
        nextD = 0;
        nextV = 0;
        while(pos < s->length() && (*s)[pos] == '-') {
            nextD++;
            pos++;
        }
        
        while(pos < s->length() && (*s)[pos] != '-') {
            nextV = nextV * 10 + (int)(*s)[pos] - (int)'0';
            pos++;
        }
        
        return true;
    }
    
    void dfs(TreeNode* node, int d) {
        if (nextD > d) {
            node->left = new TreeNode(nextV);
            if (moveNext()) {
                dfs(node->left, d + 1);
                
                if (nextD > d) {
                    node->right = new TreeNode(nextV);
                    if (moveNext()) {
                        dfs(node->right, d + 1);
                    }
                }
            }
        }
    }
    
    
public:
    TreeNode* recoverFromPreorder(string S) {
        pos = 0;
        s = &S;
        TreeNode* ans = NULL;
        if (moveNext()) {
            ans = new TreeNode(nextV);
            if (moveNext()) {
                dfs(ans, 0);
            }
        }
        
        return ans;
    }
};
