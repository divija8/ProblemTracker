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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        nodes_count(root, root->val, ans);
        return ans;
    }
    void nodes_count(TreeNode* node, int value, int &ans){
        if(node == NULL) return;
        if(node->val >= value){
            ans++;
            value = node->val;
        }
        nodes_count(node->left, value, ans);
        nodes_count(node->right, value, ans);

    }
};