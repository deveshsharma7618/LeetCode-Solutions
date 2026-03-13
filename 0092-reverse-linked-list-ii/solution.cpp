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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head->next){
            return head;
        }
        if(left == 1){
            ListNode * temp = head;
            int i = 1;
            ListNode *prev = nullptr;
            ListNode *curr = head;
            
            while(i <= right){
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                i++;
            }

            head->next = curr;
            return prev;
        }

        
        int i = 1;
        ListNode* temp = head;
        ListNode *pre = nullptr;
        while(i < left){
            pre = temp;
            temp = temp->next;
            i++;
        }

        ListNode *prev = nullptr;
        ListNode *curr = temp;
        ListNode *temp2 = curr;
        while(i <= right){
            ListNode *next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
            i++;
        }

        pre->next = prev;
        temp2->next = curr;

        return head;
        

        
    }
};
