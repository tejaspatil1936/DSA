#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *first = dummy;
        ListNode *second = dummy;

        for (int i = 0; i <= n; i++)
        {
            first = first->next;
        }

        while (first != nullptr)
        {
            first = first->next;
            second = second->next;
        }

        ListNode *nodeToDelete = second->next;
        second->next = second->next->next;
        delete nodeToDelete;

        return dummy->next;
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.removeNthFromEnd(head, 2);

    printList(head);

    return 0;
}
