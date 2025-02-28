#include <iostream>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy;

        while (head && head->next)
        {
            ListNode *first = head;
            ListNode *second = head->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            head = first->next;
        }

        return dummy.next;
    }
};

ListNode *createLinkedList(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedList(arr, size);
    cout << "Original List: ";
    printLinkedList(head);

    Solution solution;
    ListNode *swappedHead = solution.swapPairs(head);

    cout << "Swapped List: ";
    printLinkedList(swappedHead);

    return 0;
}
