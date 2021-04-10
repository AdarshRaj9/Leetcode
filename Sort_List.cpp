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
    ListNode* getMid(ListNode* head)
    {
        if(!head or !head->next)
        {
            return head;
        }
        ListNode* slow=head,*fast=head->next;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* h1,ListNode* h2)
    {
        ListNode* head=NULL,*temp=NULL;
        while(h1 and h2)
        {
            if(h1->val>h2->val)
            {
                if(!head)
                {
                    head=h2;
                    temp=h2;
                }
                else
                {
                    temp->next=h2;
                    temp=temp->next;
                }
                h2=h2->next;
            }
            else
            {
                if(!head)
                {
                    head=h1;
                    temp=h1;
                }
                else
                {
                    temp->next=h1;
                    temp=temp->next;
                }
                h1=h1->next;
            }
            if(!h1)
            {
                temp->next=h2;
            }
            else
            {
                temp->next=h1;
            }
        }
        return head;
    }
    ListNode* mergesort(ListNode* head)
    {
        if(!head or !head->next)
            return head;
        ListNode* mid=getMid(head);
        ListNode* temp=mid->next;
        mid->next=NULL;
        ListNode* h1=mergesort(head);
        ListNode* h2=mergesort(temp);
        return merge(h1,h2);
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
        
        
    }
};