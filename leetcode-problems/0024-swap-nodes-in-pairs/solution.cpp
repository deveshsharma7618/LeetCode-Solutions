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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return NULL;
        }

        if (head->next == NULL) {
            return head;
        }

        ListNode* second = head->next;
        ListNode* temp = second->next;
        second->next = head;
        head->next = swapPairs(temp);
        return second;
    }
};
