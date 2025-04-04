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
    TreeNode* findLCA(TreeNode *node,TreeNode *node1,TreeNode *node2){

        if(node1==node2){

            return node1;
        }
        if(node2==NULL){

            return node1;
        }
        if(node==node1 || node==node2){

            return node;
        }
        if(node==NULL){

            return NULL;
        }
        TreeNode *LeftRes = findLCA(node->left,node1,node2);
        TreeNode *RightRes = findLCA(node->right,node1,node2);

        if(LeftRes && RightRes){

            return node;
        }
        if(LeftRes){

            return LeftRes;
        }
        if(RightRes){

            return RightRes;
        }
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(root==NULL || (root->left==NULL && root->right==NULL)){

            return root;
        }

        queue<TreeNode*> q;
        
        q.push(root);

        while(!q.empty()){

            int sze = q.size();
            vector<TreeNode*> leaves;

            for(int i=0;i<sze;i++){

                auto node = q.front();
                q.pop();

                leaves.push_back(node);

                if(node->left){

                    q.push(node->left);

                }
                if(node->right){

                    q.push(node->right);
                }
            }

            if(q.empty()){

                return findLCA(root,leaves[0],leaves[leaves.size()-1]);
            }
        }
        return NULL;
    }
};