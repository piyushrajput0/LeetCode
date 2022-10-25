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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        
        ListNode *ans=NULL;
        ListNode *tail=ans;
        while(l1 && l2)
        {
            int x=l1->val+l2->val+carry;
            if(x>9)
            {
              carry=x/10;

                x=x%10;
                // cout<<carry<<endl;
            }
            else
            {
                carry=0;
            }
            

            ListNode *temp= new ListNode(x);
            if(ans==NULL)
            {
                ans=temp;
                tail=ans;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1)
        {
            int x=l1->val+carry;
            
            if(x>9)
            {
                carry=x/10;

                x=x%10;
            }
            else
            {
                carry=0;
            }
            
            ListNode *temp= new ListNode(x);
            if(ans==NULL)
            {
                ans=temp;
                tail=ans;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }
            
            l1=l1->next;
           
            
        }
        
        while(l2)
        {
            int x=l2->val+carry;
            
            if(x>9)
            {
                 carry=x/10;

                x=x%10;
            }
            else
            {
                carry=0;
            }
            
            ListNode *temp= new ListNode(x);
            if(ans==NULL)
            {
                ans=temp;
                tail=ans;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }

            l2=l2->next;
            
        }
        
        if(carry)
        {
            ListNode *temp= new ListNode(carry);
            if(ans==NULL)
            {
                ans=temp;
                tail=ans;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }
        }
        
        return ans;
    }
};