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
{ // Question - Linked List Random Node
public:
    ListNode *temp = NULL;
    Solution(ListNode *head)
    {
        temp = head;
    }

    int getRandom()
    {
        int res, len = 1;
        ListNode *h1 = temp;
        while (h1)
        {
            if (rand() % len == 0)
            {
                res = h1->val;
            }
            h1 = h1->next;
            len++;
        }
        return res;
    }
};
