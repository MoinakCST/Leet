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
    int ans = 0;


    int dfs(TreeNode* root){
        if(root==nullptr){
            return 0;
        }

        int rightPath = dfs(root->right);
        int leftPath = dfs(root->left);


        int rightLen = 0;
        int leftLen = 0;

        if(root->right!=nullptr && root->right->val==root->val){
            rightLen = rightPath+1;
        }

        if(root->left!=nullptr && root->left->val==root->val){
            leftLen = leftPath+1;
        }

        ans = max(ans,leftLen+rightLen);


        return max(leftLen,rightLen);

    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};