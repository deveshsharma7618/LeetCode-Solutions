class Solution {
public:
    int get_size(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        int n = get_size(head);
        k %= n;
        if (k == 0) return head;

        int steps = n - k;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (steps--) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* newHead = curr;
        prev->next = nullptr;

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head;

        return newHead;
    }
};
