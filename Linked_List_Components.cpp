// We are given head, the head node of a linked list containing unique integer values.

// We are also given the list G, a subset of the values in the linked list.

// Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

// Example 1:

// Input: 
// head: 0->1->2->3
// G = [0, 1, 3]
// Output: 2
// Explanation: 
// 0 and 1 are connected, so [0, 1] and [3] are the two connected components.


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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int>s(G.begin(),G.end());
        int c=0;
        while(head)
        {
            if(s.count(head->val) and (!head->next or !s.count(head->next->val)))
            {
                c++;
            }
            head=head->next;
        }
        return c;
        
        
    }
};