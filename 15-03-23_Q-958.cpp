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
class Solution // Question - Check Completeness of a Binary Tree
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        { // BFS Traversal
            TreeNode *top = q.front();
            q.pop();
            if (top->left)
            {
                if (flag)
                    return false;
                q.push(top->left);
            }
            else
                flag = 1;
            if (top->right)
            {
                if (flag)
                    return false;
                q.push(top->right);
            }
            else
                flag = 1;
        }
        return true;
    }
};