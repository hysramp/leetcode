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
    int ans;
    void dfs(TreeNode* node, int sum) {
        if (node == NULL) return;
        sum = sum * 2 + node->val;
        if (node->left == NULL && node->right == NULL) {
            ans += sum;
            return;
        }
        
        if (node->left) dfs(node->left, sum);
        if (node->right) dfs(node->right, sum);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};
