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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>&arr,int s,int e)
    {
        if(s>e)
            return NULL;
        if(s==e)
        {
            TreeNode* newNode=new TreeNode(arr[s]);
            return newNode;
        }
        int mid=(s+e)/2;
        TreeNode* newNode=new TreeNode(arr[mid]);
        TreeNode* l=build(arr,s,mid-1);
        TreeNode* r=build(arr,mid+1,e);
        newNode->left=l;
        newNode->right=r;
        return newNode;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>arr;
        int c=0;
        ListNode* ptr=head;
        if(!head)
            return NULL;
        while(ptr)
        {
            arr.push_back(ptr->val);
            c++;
            ptr=ptr->next;
            
        }
        return build(arr,0,c-1);
        
    }
};