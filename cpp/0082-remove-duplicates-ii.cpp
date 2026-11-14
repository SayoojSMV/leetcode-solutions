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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* current = head;
        ListNode* prev = dummy;

        while (current != nullptr) {
            bool hasDuplicates = false;

            while (current->next != nullptr && current->val == current->next->val) {
                hasDuplicates = true;
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }

            if (hasDuplicates) {
                ListNode* temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;

            } else {
                prev = prev->next;
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;  
    }
};