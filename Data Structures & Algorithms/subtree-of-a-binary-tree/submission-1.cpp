class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* subroot) {
        if (root == NULL && subroot == NULL)
            return true;

        if (root == NULL || subroot == NULL)
            return false;

        if (root->val != subroot->val)
            return false;

        return dfs(root->left, subroot->left) &&
               dfs(root->right, subroot->right);
    }

    bool dfs2(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL)
            return false;

        if (dfs(root, subRoot))
            return true;

        return dfs2(root->left, subRoot) ||
               dfs2(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs2(root, subRoot);
    }
};