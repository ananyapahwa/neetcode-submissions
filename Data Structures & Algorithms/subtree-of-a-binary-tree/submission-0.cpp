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
    bool dfs(TreeNode* root, TreeNode* subroot){
        if(root == NULL && subroot == NULL) return true;
        else if(root == NULL || subroot == NULL) return false;

        if(root->val != subroot->val) return false;

        return dfs(root->left, subroot->left) && dfs(root->right, subroot->right);
    }

    void dfs2(TreeNode* root, TreeNode* subRoot, bool &ans){
        if(root == NULL) return;

       
        bool t =  dfs(root, subRoot);
        if(t) {
            ans = true;
            return;
        }

        dfs2(root->left, subRoot, ans);
        dfs2(root->right, subRoot, ans);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;

        dfs2(root, subRoot, ans);
        return ans;
    }
};
