class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(a && b){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = a ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* head = nullptr;
        for(ListNode* lst : lists){
            head = merge(head, lst);
        }
        return head;
    }
};
