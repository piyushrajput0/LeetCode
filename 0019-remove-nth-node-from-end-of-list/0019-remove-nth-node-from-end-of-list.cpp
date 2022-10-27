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
        
        if(head->next==NULL)
        {
            return NULL;
        }
        
        
        int cn=n; //count
        ListNode *curr=head;
        while(cn-- && curr)
        {
            curr=curr->next;
        }
        
        if(curr==NULL)
        {
            return head->next;
        }
        
        ListNode*dup=head;
        while(curr->next)
        { 
            curr=curr->next;
            dup=dup->next;
            
        }
        
        if(dup->next->next==NULL)
        {
            dup->next=NULL;
        }
        else
        dup->next=dup->next->next;
        
        return head;
        
    }
};
