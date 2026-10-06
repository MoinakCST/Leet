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
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

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