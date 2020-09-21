//111. 二叉树的最小深度

/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。。
*/

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
public:
    int minDepth(TreeNode* root) {
        if(root == NULL ) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        return  (root->left == 0 ||root->right == 0)? left+right+1:min(left,right) + 1;
    }
};