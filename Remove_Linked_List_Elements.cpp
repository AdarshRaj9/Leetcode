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
    
    ListNode* del(ListNode* head,int val)
    {
        if(!head)
            return head;
        while(head and head->val==val)
        {
            head=head->next;
        }
        ListNode* ptr=head;
        while(ptr and ptr->next)
        {  
            if(ptr->next->val==val)
            {
                ptr->next=ptr->next->next;
            }
            else
            {
                ptr=ptr->next;
            }
        }
        
        return head;
        
    }
    ListNode* removeElements(ListNode* head, int val) {
        
        return del(head,val);
        
    }
};


