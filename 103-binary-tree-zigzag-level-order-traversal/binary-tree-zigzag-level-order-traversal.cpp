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
       bool zigzag = true;
       queue<TreeNode *>q;
       vector<vector<int>>ans;
       if(root == NULL){
        return ans;
       }
       q.push(root);
       while(!q.empty()){
        int size = q.size();
        vector<int>level(size);
        for(int i = 0;i < size;i++){
            TreeNode *node = q.front();
            q.pop();
            int index = zigzag ? i : (size-1-i);
            level[index] = node->val;
            if(node->left) q.push(node->left);
            if(node -> right) q.push(node -> right);
        }
        zigzag = !zigzag;
        ans.push_back(level);
       }
       return ans;
    }
};