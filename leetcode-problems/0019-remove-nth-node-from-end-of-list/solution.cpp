class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* front = head;
        for(int i = 0; i < n; i++) {
            front = front->next;
        }

        if(!front) return head->next;

        ListNode* start = head;
        while(front->next) {
            front = front->next;
            start = start->next;
        }

        start->next = start->next->next;
        return head;
    }
};
