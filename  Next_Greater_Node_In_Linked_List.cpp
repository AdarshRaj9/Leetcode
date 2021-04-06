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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;//,ans;
        stack<int>s;
        ListNode* ptr=head;
        while(ptr)
        {
            arr.push_back(ptr->val);
            ptr=ptr->next;
        }
        vector<int>ans(arr.size(),0);
        for(auto i=0;i<arr.size();++i)
        {
            while(!s.empty() and arr[i]>arr[s.top()])
            {
                ans[s.top()]=arr[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
        
        
        
    }
};


