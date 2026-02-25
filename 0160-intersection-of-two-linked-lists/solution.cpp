/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode* t2 = headB;
        while(t1){
            ListNode *x = t2;
            while(x){
                if(x == t1){
                    return t1;
                }
                x = x->next;
            }
            t1 = t1->next;
        }
        return nullptr;
    }
};
