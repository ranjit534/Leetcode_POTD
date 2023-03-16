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
class Solution
{ // Question - Construct Binary Tree from Inorder and Postorder Traversal
public:
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &m, int s, int e, int &root)
    {
        if (s > e)
        {
            return NULL;
        }
        int rootIndex = m[postorder[root]];
        TreeNode *r = new TreeNode(postorder[root]);
        root--;
        r->right = solve(inorder, postorder, m, rootIndex + 1, e, root);
        r->left = solve(inorder, postorder, m, s, rootIndex - 1, root);
        return r;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        int root = postorder.size() - 1;
        return solve(inorder, postorder, m, 0, inorder.size() - 1, root);
    }
};