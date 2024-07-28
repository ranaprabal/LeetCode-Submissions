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

// ListNode* rec(ListNode* l1, ListNode* l2,int carry)
// {
//     if(l1==NULL && l2==NULL)
//     {
//         if(carry)
//         {
//             ListNode p = new ListNode;
//             l1->next=p;
//             p->val=carry;
//         }
//         return l1;
//     }
//     if(l1==NULL && l2)
//     {
//         if(carry)
//         {
//             ListNode p = l2;
//             while(p->val==9)
//             {
//                 p->val=0;
//                 p=p->next;
//             }
//             p->val
//         }
//         return l2;
//     }
// }

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode;
        ListNode* head = temp;
        int carry = (l1->val + l2->val) / 10;
        temp->val = (l1->val + l2->val) % 10;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2) {
            ListNode* t = new ListNode;
            t->val = (carry + l1->val + l2->val) % 10;
            carry = (carry + l1->val + l2->val) / 10;
            temp->next = t;
            temp = t;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            ListNode* t = new ListNode;
            t->val = (carry + l1->val) % 10;
            carry = (carry + l1->val) / 10;
            temp->next = t;
            temp = t;
            l1=l1->next;
        }
        while(l2){
            ListNode* t = new ListNode;
            t->val = (carry + l2->val) % 10;
            carry = (carry + l2->val) / 10;
            temp->next = t;
            temp = t;
            l2=l2->next;
        }
        if(carry){
            ListNode* t = new ListNode;
            t->val = (carry) % 10;
            temp->next = t;
            temp = t;
        }
        return head;
    }
};