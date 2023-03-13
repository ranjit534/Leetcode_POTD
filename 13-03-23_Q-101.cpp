class Solution
{ // Question - Symmetric Tree
public:
    bool isMirror(TreeNode *a, TreeNode *b)
    {
        if (a == NULL && b == NULL)
            return true;
        else if (a == NULL || b == NULL)
            return false;
        else if (a->val != b->val)
            return false;
        else
            return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        else
            return isMirror(root->left, root->right);
    }
};