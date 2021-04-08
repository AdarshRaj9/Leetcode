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
        if(!head)
            return 0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* swapPairs(ListNode* head) {
        //int c=0;
        if(!head)
            return NULL;
        if(!head->next)
        {
            return head;
        }
        ListNode* temp=head;
        int c=count(temp);
        
        ListNode* slow=head,*fast=head->next;
        if(c%2==0)
        {
        while(fast->next)
        {
            //c++;
            swap(slow->val,fast->val);
            slow=slow->next->next;
            fast=fast->next->next;
        }
        swap(slow->val,fast->val);
        }
        else
        {
            while(fast and fast->next)
        {
            swap(slow->val,fast->val);
            slow=slow->next->next;
            fast=fast->next->next;
        }
        }
        return head;
        
        // if (!head || !(head->next))
        // return head;
        // ListNode *res = head->next;
        // head->next = swapPairs(res->next);
        // res->next = head;
        // return res;
        
    }
};