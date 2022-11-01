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
    
    ListNode *midnode(ListNode *head)
    {
        if(head==NULL)
        {
            return head;
        }
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    ListNode* mergelist(ListNode* list1,ListNode *list2)
    {
        ListNode *curr=new ListNode (-1);
        ListNode *tail=curr;
         while(list1 && list2)
         {
             if(list1->val<list2->val)
             {
                 tail->next=new ListNode(list1->val);
                 
                 
                 list1=list1->next;
                 tail=tail->next;
             }
             else
             {
                 tail->next=new ListNode(list2->val);
                 
                 
                 list2=list2->next;
                 tail=tail->next;
             }
         }
        
        while(list1)
        {
            tail->next=new ListNode(list1->val);
                 
                 
                 list1=list1->next;
                 tail=tail->next;
        }
        
        while(list2)
        {
            tail->next=new ListNode(list2->val);
                 
                 
                 list2=list2->next;
                 tail=tail->next;
        }
        
        return curr->next;
    }
    ListNode* merge(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head ;
        }
        ListNode *mid=midnode(head);
        ListNode *temp=mid->next;
        mid->next=NULL;
        ListNode *list1=merge(head);
        ListNode *list2=merge(temp);
       return mergelist(list1,list2);
        
        
        
    }
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL)
        {
            return head;
        }
        return merge(head);
    }
};