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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx, int start, int end){
        if(idx >= preorder.size()) return NULL;
        if(start > end) return NULL;

        int r = preorder[idx++];
        TreeNode* root = new TreeNode(r);

        //find that node in inorder
        int t;
        for(int i=start; i<= end; i++){
            if(inorder[i] == r){
                t=i;
                break;
            }
        }

        root->left = solve(preorder, inorder, idx, start, t-1);
        root->right = solve(preorder, inorder, idx, t+1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return solve(preorder, inorder, preIdx, 0, preorder.size()-1);
    }
};
