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
    //counter till we get kth element in the inorder traversal
    int solve(TreeNode* root, int k, int& cnt){
        if(root == NULL) return -1;

        int left = solve(root->left, k, cnt);
        if(left != -1) return left;
        cnt+=1;
        if(cnt == k) return root->val;
        return solve(root->right, k, cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return solve(root, k, cnt);
    }
};
