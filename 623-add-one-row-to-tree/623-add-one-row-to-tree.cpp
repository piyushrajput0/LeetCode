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
    
    void helper(TreeNode *root, int val,int depth,int height,TreeNode *prev)
    {
         if(root==NULL)
        {
            return ;
        }
       
        if(depth==height)
        {
            TreeNode* left1=root->left;
            TreeNode * right1=root->right;
            root->left=new TreeNode(val);
            root->right=new TreeNode(val);
            
            if(left1)
            {
                root->left->left=left1;
            }
            
            if(right1)
            {
                root->right->right=right1;
            }
            
            return;
            
        }
        
        helper(root->left,val,depth,height+1,root);
        helper(root->right,val,depth,height+1,root);
        
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode * node = new TreeNode(val,NULL,NULL);
            node->left=root;
            
            root=node;
        }
        depth-=1;
        
        
        helper(root,val,depth,1,root);
        return root;
        
    }
};
