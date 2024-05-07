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
    ListNode* doubleIt(ListNode* head) {
        ListNode* cur = head;
        ListNode *prev = NULL,*next2 = NULL;
        while(cur!=NULL){
            next2 = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next2;
        }
        cur = prev,next2=prev;
        int carry = 0;
        while(prev){
            int temp = prev->val*2 + carry;
            prev->val = temp%10;
            carry = temp/10;
            next2 = prev;
            prev=prev->next;
        }
        if(carry){
            ListNode* temp = new ListNode;
            temp->val = 1;
            temp->next = NULL;
            next2->next = temp;
        }

        prev = NULL,next2=NULL;
        while(cur!=NULL){
            next2 = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next2;
        }
        head = prev;
        return head;

    }
};