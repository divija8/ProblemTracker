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
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int numOfNodes = preorder.size();

        vector<int> indexInPostorder(numOfNodes + 1);
        // for (int index = 0; index < numOfNodes; index++) {
        //     // Store the index of the current element
        //     indexInPostorder[postorder[index]] = index;
        // }
        unordered_map<int, int>pmap;
        for(int i = 0;i<preorder.size();i++){
            pmap[postorder[i]] = i;
        }

        return constructTree(0, numOfNodes - 1, 0, preorder, pmap);
    }

private:
    TreeNode* constructTree(int preStart, int preEnd, int postStart,
                            vector<int>& preorder,
                            unordered_map<int, int>&pmap) {
        if (preStart > preEnd) return NULL;

        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int leftRoot = preorder[preStart + 1];

        int numOfNodesInLeft = pmap[leftRoot] - postStart + 1;

        TreeNode* root = new TreeNode(preorder[preStart]);

        root->left = constructTree(preStart + 1, preStart + numOfNodesInLeft,
                                   postStart, preorder, pmap);

        root->right = constructTree(preStart + numOfNodesInLeft + 1, preEnd,
                                    postStart + numOfNodesInLeft, preorder,
                                    pmap);

        return root;
    }
};