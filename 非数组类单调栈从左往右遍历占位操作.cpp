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
    stack<pair<int,int>>st;
    vector<int>ans;
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int count=0;
        while(head){
            int cur=head->val;
            while(!st.empty()&&cur>st.top().second){
                ans[st.top().first]=cur;
                st.pop();
            }
            head=head->next;
            st.push({count,cur});
            ans.push_back(0);
            count++;
        }
        
        return ans;
    }
};
