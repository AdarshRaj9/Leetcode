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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(),*pre=dummy;
        if(!head or m==n)
            return head;
        dummy->next=head;
        for(int i=0;i<m-1;++i)
        {
            pre=pre->next;
        }
        ListNode* tail=pre->next;
        for(int i=0;i<n-m;++i)
        {
            ListNode* temp=pre->next;
            pre->next=tail->next;
            tail->next=tail->next->next;
            pre->next->next=temp;
            
            
        }
        return dummy->next;
        
        
    }
};