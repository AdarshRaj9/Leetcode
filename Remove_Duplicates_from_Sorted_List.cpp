
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
    void remove(ListNode* head)
    {
        if(!head)
            return ;
        ListNode* ptr=head;
        ListNode* nextNode;


        while(ptr and ptr->next)
        {
            
            if(ptr->val==ptr->next->val)
            {
                nextNode=ptr->next->next;
                delete (ptr->next);
                ptr->next=nextNode;
            }
            else
                ptr=ptr->next;
        } 
    }
    ListNode* deleteDuplicates(ListNode* head) {
        remove(head);
        
        
        return head;
        
     
    }
};