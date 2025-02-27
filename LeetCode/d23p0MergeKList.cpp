#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator for min-heap
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (ListNode* list : lists) {
            if (list) minHeap.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            tail->next = minNode;
            tail = tail->next;

            if (minNode->next) {
                minHeap.push(minNode->next);
            }
        }

        return dummy.next;
    }
};

// Function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    vector<vector<int>> inputLists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;

    for (const auto& values : inputLists) {
        lists.push_back(createLinkedList(values));
    }

    Solution solution;
    ListNode* mergedHead = solution.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printLinkedList(mergedHead);

    return 0;
}
