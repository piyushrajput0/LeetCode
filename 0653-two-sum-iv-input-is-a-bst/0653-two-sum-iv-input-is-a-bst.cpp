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
    vector<int>v;
    
     void fillmap(TreeNode *root)
     {
         if(root==NULL)
         {
             return ;
         }
         
         mp.insert({root->val,v.size()});
         v.push_back(root->val);
         fillmap(root->left);
         fillmap(root->right);
         
     }
    bool findTarget(TreeNode* root, int k) {
        
        if(root==NULL)
        {
            return false;
        }
        
      
        
        fillmap(root);
        
        int n=v.size();
        
         
               
               
        for(int i=0;i<n;i++)
        {
            // cout<<k-root->val<<endl;
            if(mp.find(k-v[i])!=mp.end() )
            {
                // cout<<mp[k-v[i]]<<" "<<i<<endl;
                if( mp[k-v[i]]!=i)
                return true;
            }
            
        }
        
        return false;
        
    }
};