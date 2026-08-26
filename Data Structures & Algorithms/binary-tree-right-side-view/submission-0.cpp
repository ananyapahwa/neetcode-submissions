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
    void dfs(TreeNode* root, map<int, int>& levels, int level){
        if(root == NULL) return ;

        if(levels.find(level) == levels.end()){
            levels[level] = root->val;
        }

        dfs(root->right, levels, level+1);
        dfs(root->left, levels, level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        //first node on each level going on right side first
        map<int, int> levels;
        vector<int> ans;

        dfs(root, levels, 0);

        for(auto l:levels){
            ans.push_back(l.second);
        }

        return ans;
    }
};
