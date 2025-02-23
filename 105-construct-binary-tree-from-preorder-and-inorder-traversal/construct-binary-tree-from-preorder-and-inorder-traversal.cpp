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
    unordered_map<int, int>cmap;
    int index = 0;
    TreeNode* arrayToTree(vector<int>&preorder, int left, int right){
        if(left > right) return nullptr;
        int rootvalue = preorder[index++];
        TreeNode* root_val = new TreeNode(rootvalue);
        root_val->left = arrayToTree(preorder, left, cmap[rootvalue]-1);
        root_val->right = arrayToTree(preorder, cmap[rootvalue]+1, right);
        return root_val;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++){
            cmap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, preorder.size()-1);
    }
};