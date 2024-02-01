/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

// @lc code=start
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


 /**
  * @brief 合并二叉树
  * 
  */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};
// @lc code=end

//* 使用新节点合并二叉树
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr) return root2;
    if(root2 == nullptr) return root1;
    
    TreeNode* root = new TreeNode(0);

    root->val = root1->val + root2->val;
    root->left = mergeTrees(root1->left, root2->left);
    root->right = mergeTrees(root1->right, root2->right);

    return root;
}

//* 不使用新节点合并二叉树
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr) return root2;
    if(root2 == nullptr) return root1;
    
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}