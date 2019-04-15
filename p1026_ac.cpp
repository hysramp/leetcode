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
    int ans = 0;
    void dfs(TreeNode* root, int s, int e) {
        int sn = root->val < s ? root->val : s;
        int en = root->val > e ? root->val : e;
        
        ans = en - sn > ans ? en - sn : ans;
        
        if (root->left) {
            dfs(root->left, sn, en);
        }
        
        if (root->right) {
            dfs(root->right, sn, en);
        }
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root) {
            dfs(root, 100001, -1);
        }
        
        return ans;
    }
};
