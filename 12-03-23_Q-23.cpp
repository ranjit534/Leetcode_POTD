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
class Solution
{ // Question - Merge k Sorted Lists
public:
    ListNode *merge(ListNode *a1, ListNode *a2)
    {
        if (a1 == NULL)
            return a2;
        else if (a2 == NULL)
            return a1;
        if (a1->val <= a2->val)
        {
            a1->next = merge(a1->next, a2);
            return a1;
        }
        else
        {
            a2->next = merge(a1, a2->next);
            return a2;
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        int n = lists.size();
        while (n > 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                lists[i] = merge(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }
        return lists[0];
    }
};