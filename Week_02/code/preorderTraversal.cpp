//144. 二叉树的前序遍历

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
    vector<int> ans;
    void preorder(TreeNode *root)
    {
        if(root == NULL) return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
    
        //非递归
    #if 1
        stack<TreeNode*> st;
        vector<int> res;
        if(root == NULL) return res;
        st.push(root);

        TreeNode*curr = root;
        while( !st.empty()){
            curr = st.top();
            res.emplace_back(curr->val);
            st.pop();
            if(curr->right)  st.push(curr->right);

            if(curr->left) st.push(curr->left);

        }
        return res;
    #endif
    
        //递归
    #if 0
        preorder(root);
        return ans;
    #endif
    }
};