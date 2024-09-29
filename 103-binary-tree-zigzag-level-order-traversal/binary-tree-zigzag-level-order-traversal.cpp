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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*>nodesQueue;
        bool lefttoRight = true;
        if(root == NULL){
            return result;
        }
        nodesQueue.push(root);
        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int>row(size);
            for(int i = 0;i<size;i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                int index = lefttoRight ? i : (size-1-i);
                row[index] = node->val;
                if(node->left){
                    nodesQueue.push(node->left);
                }
                if(node->right){
                    nodesQueue.push(node->right);
                }
            }
         lefttoRight = !lefttoRight;
         result.push_back(row);
        }
        return result;
    }
};