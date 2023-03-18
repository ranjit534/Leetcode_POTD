class BrowserHistory // Question - Design Browser History
{
public:
    class Node
    {
    public:
        string data;
        Node *next;
        Node *prev;
        Node(string d)
        {
            data = d;
            next = NULL;
            prev = NULL;
        }
    };
    Node *head = NULL, *cur = NULL;
    BrowserHistory(string homepage)
    {
        Node *m = new Node(homepage);
        head = m;
        cur = m;
    }

    void visit(string url)
    {
        Node *temp = new Node(url);
        if (cur->next != NULL)
        {
            cur->next->prev = NULL;
        }
        cur->next = temp;
        temp->prev = cur;
        cur = cur->next;
    }

    string back(int steps)
    {
        while (cur->prev != NULL && steps--)
        {
            cur = cur->prev;
        }
        return cur->data;
    }

    string forward(int steps)
    {
        while (cur->next != NULL && steps--)
        {
            cur = cur->next;
        }
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */