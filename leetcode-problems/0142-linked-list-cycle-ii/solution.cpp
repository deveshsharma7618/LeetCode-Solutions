class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Phase 2: find entry
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};

