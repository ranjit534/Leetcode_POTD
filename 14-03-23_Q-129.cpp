class Solution
{ // Question - Sum Root to Leaf Numbers
public:
    void rec(TreeNode *root, int temp, int &ans) // DFS
    {
        if (root->left == NULL && root->right == NULL) // Check for leaf node
        {
            temp = temp * 10 + root->val;
            ans += temp;
            return;
        }
        temp = temp * 10 + root->val;
        if (root->left)
            rec(root->left, temp, ans);
        if (root->right)
            rec(root->right, temp, ans);
        return;
    }
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;
        if (root == NULL)
            return 0;
        rec(root, 0, ans);
        return ans;
    }
};