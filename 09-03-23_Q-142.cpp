class Solution
{ // Question-Linked List Cycle II.
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL) // If list has 0 or 1 element
            return NULL;
        ListNode *s = head, *f = head;
        while (f && f->next)
        { // Floyd's cycle finding algorithm
            s = s->next;
            f = f->next->next;
            if (s == f)
                break;
        }
        if (s != f) // If cycle not found
            return NULL;
        s = head;
        while (s != f)
        {
            s = s->next;
            f = f->next;
        }
        return f;
    }
};