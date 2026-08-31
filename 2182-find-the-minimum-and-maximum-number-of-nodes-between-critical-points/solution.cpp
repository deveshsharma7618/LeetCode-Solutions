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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;

        // single node
        // if(temp->next == nullptr){
        //     return { -1, -1};
        // }

        // double node
        temp = temp->next;
        if(!temp->next){
            return { -1, -1};
        }

        ListNode* nextPtr = temp->next;
        ListNode* prevPtr = head;
        ListNode* currPtr = temp;
        int i = 2;

        vector<int> arr;

        while(nextPtr){
            // local minima
            if(nextPtr->val > currPtr->val && currPtr->val < prevPtr->val){
                arr.push_back(i);
            }

            // local maxima
            if(nextPtr->val < currPtr->val && currPtr->val > prevPtr->val){
                arr.push_back(i);
            }

            i++;
            prevPtr = currPtr;
            currPtr = nextPtr;
            nextPtr = nextPtr->next;
        }

        if(arr.size() <= 1){
            return {-1,-1};
        }else if(arr.size() == 2){
            return { arr[1] - arr[0], arr[1] - arr[0]};
        }else {
            int minDist = INT_MAX;


            for(int i = 0; i < arr.size()-1; i++){
                int diff = arr[i+1] - arr[i];
                if(diff < minDist){
                    minDist = diff;
                }
            }

            return { minDist, arr[arr.size()-1] - arr[0]};

        }

        return { -1, -1};


    }
};
