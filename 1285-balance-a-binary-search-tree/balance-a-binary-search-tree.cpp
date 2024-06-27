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
    vector<int>sortedarr;
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return sortedArray(0, sortedarr.size()-1);
    }
    void inorderTraversal(TreeNode* root){
        if(root == NULL) return;
        inorderTraversal(root->left);
        sortedarr.push_back(root->val);
        inorderTraversal(root->right); 
    }
    TreeNode* sortedArray(int start, int end){
        if(start > end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(sortedarr[mid]);
        root->left = sortedArray(start, mid-1);
        root->right = sortedArray(mid+1, end);
        return root;
    }
};