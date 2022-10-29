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
    
    unordered_map<int,int>mp;
    TreeNode* help(int &i,vector<int>&preorder,vector<int>&inorder,int left,int right)
    {
        if(left>right || i==preorder.size())
        {
            return NULL;
        }
        
        TreeNode *node=new TreeNode(preorder[i]);
        int x=mp[preorder[i]];
        
        i+=1;
        
        node ->left=help(i,preorder,inorder,left,x-1);
        node ->right=help(i,preorder,inorder,x+1,right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int i=0;
        return help(i,preorder,inorder,0,inorder.size()-1);
        
    }
};