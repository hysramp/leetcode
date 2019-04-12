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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<size_t, int>> s;
        
        vector<int> ans;
        
        ListNode* last = head;
        head = head->next;
        size_t ct = 0;
        while(head) {
            int candidate = 0;
            if (head && head->val > last->val) {
                candidate = head->val;
                while(!s.empty() && head->val > s.top().second) {
                    ans[s.top().first] = head->val;
                    s.pop();
                }
            } else {
                s.push(pair<size_t, int>(ct, last->val));
            }
            ans.push_back(candidate);
            ct++;
            last = head;
            head = head->next;
        }
        ans.push_back(0);
        return ans;
    }
};
