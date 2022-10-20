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
    
    // int ans=INT_MIN;
    int help(TreeNode *root,int &sum)
    {
         if(root==NULL)
        {
             
            return 0l;
        }
        
        int left=help(root->left,sum);
        
        int right=help(root->right,sum);
        
        int straight=max({root->val,left+root->val,right+root->val});
        int curve=left+right+root->val;
        sum=max({sum,straight,curve});
        
        return straight;
        
       
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        int sum=INT_MIN;
        help(root,sum);
        return sum;
        
        
       
        
        
    }
};