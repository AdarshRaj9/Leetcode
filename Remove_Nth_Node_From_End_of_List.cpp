// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Follow up: Could you do this in one pass?


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]


// Double pass

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        ListNode* ptr=head,*ptr1;
        int c=count(ptr);
        if(c-n<0)
            return NULL;
        if(c==n)
            return head->next;
        ptr=head;
        for(int i=1;i<c-n;++i)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;        
        return head;
        
    }
};

// Single Pass

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head,*fast=head;
        for(int i=1;i<=n;++i)
        {
            fast=fast->next;
        }
        if (fast == nullptr) 
            return head->next;
        while(fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
        
        
    }
};

