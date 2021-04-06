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
    int count(ListNode* head)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode* ptr=head,*ptr1;
        int c=count(ptr);
        ptr=head;
        for(int i=1;i<k;++i)
        {
            ptr=ptr->next;
        }
        ptr1=head;
        for(int i=1;i<c-k+1;++i)
        {
            ptr1=ptr1->next;
        }
        swap(ptr->val,ptr1->val);
        return head;
        
        
        
        
    }
};