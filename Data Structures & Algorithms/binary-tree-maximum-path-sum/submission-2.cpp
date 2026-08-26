/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        
        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right, ans));
        //answer through the root
        ans = max(ans, root->val+left+right);

        //answer not through the root as the root
        return max(root->val, root->val + max(left, right));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int t= solve(root, ans);
        return ans;
    }
};
