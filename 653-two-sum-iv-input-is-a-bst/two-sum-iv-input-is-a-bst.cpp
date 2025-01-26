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
    void pushLeft(TreeNode* root, stack<TreeNode*> &st1)
    {
        while(root)
        {
            st1.push(root);
            root = root->left;
        }
    }
    void pushRight(TreeNode* root, stack<TreeNode*> &st2)
    {
        while(root)
        {
            st2.push(root);
            root = root->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st1; //left;
        stack<TreeNode*> st2; //right;
        pushLeft(root, st1);
        pushRight(root, st2);
        while(st1.top()!=st2.top())
        {
            int sum = st1.top()->val+st2.top()->val;
            if(sum==k) return true;
            else if(sum>k) 
            {
                TreeNode* temp = st2.top();
                st2.pop();
                pushRight(temp->left, st2);
            }
            else
            {
                TreeNode* temp = st1.top();
                st1.pop();
                pushLeft(temp->right, st1);
            }
        }
        return false;
    }
};