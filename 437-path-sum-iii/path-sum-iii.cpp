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
    int solve_Sum(TreeNode* node, long long sum, int targetSum, unordered_map<long long, int>&mpp){
        if(!node) return 0;
        sum += node->val;
        int count = mpp[sum - targetSum];
        mpp[sum]++;
        count+= solve_Sum(node->left, sum, targetSum, mpp);
        count+= solve_Sum(node->right, sum, targetSum, mpp);
        mpp[sum]--;
    return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>mpp;
        mpp[0] = 1;
         return solve_Sum(root, 0, targetSum, mpp);
    }
};