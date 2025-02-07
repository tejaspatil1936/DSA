// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

#include <iostream>
#include <vector>

// Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(std::vector<int> nums)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *current = dummyHead;
    for (int num : nums)
    {
        current->next = new ListNode(num);
        current = current->next;
    }
    return dummyHead->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Example usage:
    Solution solution;

    // Create two linked lists representing numbers
    std::vector<int> num1 = {2, 4, 3};
    std::vector<int> num2 = {5, 6, 4};
    ListNode *l1 = createLinkedList(num1);
    ListNode *l2 = createLinkedList(num2);

    // Add the two numbers represented by the linked lists
    ListNode *sum = solution.addTwoNumbers(l1, l2);

    // Print the result
    std::cout << "Sum: ";
    printLinkedList(sum); // Expected output: 7 0 8

    // Clean up memory (important to prevent memory leaks)
    while (l1 != nullptr)
    {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr)
    {
        ListNode *temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (sum != nullptr)
    {
        ListNode *temp = sum;
        sum = sum->next;
        delete temp;
    }

    return 0;
}
