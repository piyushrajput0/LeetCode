/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *curr=head;
        while(curr)
        {
            Node * tempnode= new Node(curr->val);
            tempnode->next=curr->next;
            curr->next=tempnode;
            curr=tempnode->next;
            
        }
        
        curr=head;
        while(curr)
        {
            curr->next->random=curr->random==NULL?NULL:curr->random->next;
            curr=curr->next->next;
        }
        
        Node *ans=NULL;
        Node *tail=NULL;
        curr=head;
        while(curr)
        {
            if(ans==NULL)
            {
                ans=curr->next;
                tail=curr->next;
                
            }
            else
            {
                tail->next=curr->next;
                tail=tail->next;
            }
            curr->next=curr->next->next;
            curr=curr->next;
        }
        
        return ans;
        
    }
};