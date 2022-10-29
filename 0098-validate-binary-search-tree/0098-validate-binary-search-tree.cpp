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
    int flag=0;
    void left(TreeNode *root,int value)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->val>=value)
        {
            flag=1;
            
        }
        
        if(flag)
        {
            return ;
        }
        
        left(root->left,value);
        left(root->right,value);
        
    
    }
    
    void right(TreeNode *root,int value)
    {
        if(root==NULL)
        {
            return ;
        }
        
        if(root->val<=value)
        {
            flag=1;
            
        }
        
        if(flag)
        {
            return ;
        }
        
        right(root->left,value);
        right(root->right,value);
        
    
    }
    bool isValidBST(TreeNode* root) {
        
       
        
        left(root->left,root->val);
        right(root->right,root->val);
        
        if(flag)
        {
            return false;
        }
        else
        {
            if(root->left)
            isValidBST(root->left);
            
            if(root->right)
            isValidBST(root->right);
        }
        
        
        return flag==1?false:true;
     
        
        
        
    }
};