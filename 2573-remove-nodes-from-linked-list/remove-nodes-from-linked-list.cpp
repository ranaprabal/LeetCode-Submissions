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
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        ListNode* dummy = head;
        while (dummy) {
            v.push_back(dummy->val);
            dummy = dummy->next;
        }
        vector<int> ans;
        int cur = 0;
        reverse(v.begin(), v.end());
        for (auto& it : v) {
            if (it >= cur) {
                ans.push_back(it);
                cur = it;
            }
        }

        reverse(ans.begin(), ans.end());
        dummy = head;
        int n = ans.size();
        for (int i = 0; i < n; i++) {
            dummy->val = ans[i];
            if (i == n - 1)
                dummy->next = NULL;
            else
                dummy = dummy->next;
        }
        return head;
    }
};