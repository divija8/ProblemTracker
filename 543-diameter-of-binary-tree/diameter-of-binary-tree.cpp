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
// class Solution {
// public:
//     int res = 0;
//     int dia(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }
//         int lh = dia(root->left);
//         int rh = dia(root->right);
//         return (1 + max(lh, rh));
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         int lh = dia(root->left);
//         int rh = dia(root->right);
//         res = max(res, (lh + rh));
//         diameterOfBinaryTree(root->left);
//         diameterOfBinaryTree(root->right);
//         return res;
//     }
// };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        int maxH = max(leftH, rightH);
        int totalH = 1 + maxH;
        return totalH;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = maxDepth(root->left) + maxDepth(root->right);
        int ans = max(option1, max(option2, option3));
        return ans;
    }
};