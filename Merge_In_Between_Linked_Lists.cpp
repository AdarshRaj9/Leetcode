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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head1=list1,*head2=list1;
        for(int i=0;i<a-1;++i)
        {
            head1=head1->next;
        }
        for(int i=0;i<b;++i)
        {
            head2=head2->next;
        }
        head1->next=list2;
        while(list2->next)
        {
            list2=list2->next;
        }
        list2->next=head2->next;
        return list1;
        
        
    }
};

 
 