/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution
{ // Question - Convert Sorted List to Binary Search Tree
public:
    TreeNode *rec(int l, int r, unordered_map<int, ListNode *> &m1)
    {
        if (l > r)
            return NULL;
        int mid = (l + r) / 2;
        ListNode *m = m1[mid];
        TreeNode *ans = new TreeNode(m->val);
        ans->left = rec(l, mid - 1, m1);
        ans->right = rec(mid + 1, r, m1);
        return ans;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        int r = 0;
        unordered_map<int, ListNode *> m1;
        ListNode *temp = head;
        while (temp)
        {
            m1[r] = temp;
            temp = temp->next;
            r++;
        }
        return rec(0, r - 1, m1);
    }
};