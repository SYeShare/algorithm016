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
    map<int,int> hash;
    vector<int> pos;

    TreeNode* buildTree(int ps, int pe, int is, int ie){
        if(ps > pe || is > ie){
            return NULL;
        }
        int root = pos[ps];
        int ri = hash[root];

        TreeNode* node = new TreeNode(root);
        node->left = buildTree(ps+1,ps+ri-is,is,ri-1);
        node->right = buildTree(ps+ri-is+1,pe,ri+1,ie);

        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        while(i < inorder.size()){
            hash[inorder[i]] = i;
            i++;
        }
        pos = preorder;

        TreeNode* node = buildTree(0,pos.size()-1,0,inorder.size()-1);

        return node;
    }
};