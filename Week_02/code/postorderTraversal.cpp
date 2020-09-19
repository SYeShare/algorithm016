//145. 二叉树的后序遍历
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
    void helper(TreeNode* node, vector<int> &res){
        if(node == nullptr) return;
        if(node->left) helper(node->left,res);
        if(node->right) helper(node->right,res);
        res.emplace_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)  return res;
    
    //非递归https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/a-li-mian-shi-ti-zhi-yong-zhan-qu-zuo-er-cha-shu-d/
    #if 1
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* curr = root;
        
        while(!st.empty()){
            curr = st.top();
            if(curr == nullptr){
                st.pop();
                res.emplace_back(st.top()->val);
                st.pop();
                continue;
            }
            st.push(nullptr);

            if(curr->right) st.push(curr->right);
            if(curr->left)  st.push(curr->left);
        }
        
        return res;

    #endif

        //递归
    #if 0
        helper(root,res);
        return res;
    #endif


    }
};