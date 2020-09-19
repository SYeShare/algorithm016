//94. 二叉树的中序遍历

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
    void helper(TreeNode* root,vector<int> &res){
        if(root == NULL)  return ;
        if(root->left) helper(root->left,res);
        if(root)  res.emplace_back(root->val);
        if(root->right)  helper(root->right,res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
        //非递归
    #if 0
        stack<TreeNode*> st;
        vector<int> res;

        TreeNode* curr = root;
        
        while(curr != NULL || !st.empty() ){
            while(curr!= NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.emplace_back(curr->val);
            curr = curr->right;

        }
        return res;
    
    #endif



        //递归
    #if 1
        vector<int> res;
        helper(root,res);
        return res;


    #endif
    }
};