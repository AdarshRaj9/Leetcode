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
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* ptr=root;
        int c=count(ptr);
        ptr=root;
        int r=c%k;
        int part=c/k;
        vector<ListNode*>res(k);
        for(int i=0;i<k;++i)
        {
            int remaining=part;
            if(r>0)
            {
                ++remaining;
                --r;
            }
            res[i]=ptr;
            ListNode* prev=nullptr;
            while(remaining--)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            if(prev)
            {
                prev->next=nullptr;
            }
            
        }
        return res;
        
        
    }
};