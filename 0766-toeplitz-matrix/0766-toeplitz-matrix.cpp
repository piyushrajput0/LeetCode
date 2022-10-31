class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int y=m-1;y>=0;y--)
        {
            int i=0;
            // int flag=0;
            int j=y;
            unordered_map<int,int>mp;
            while(true)
            {
                if(i>=n || j>=m)
                {
                    // cout<<1<<endl;
                    break;
                }
                mp[matrix[i][j]]++;
                if(mp.size()>1)
                {
                    // cout<<i<<" "<<j<<endl;
                    return false;
                }
                i++;
                j++;
                
            }
            
        }
        
        
        for(int x=n-1;x>0;x--)
        {
            int i=x;
            // int flag=0;
            int j=0;
            unordered_map<int,int>mp;
            while(true)
            {
                if(i>=n || j>=m)
                {
                    // cout<<1<<endl;
                    break;
                }
                mp[matrix[i][j]]++;
                if(mp.size()>1)
                {
                    // cout<<i<<" "<<j<<endl;
                    return false;
                }
                i++;
                j++;
                
            }
            
        }
        
        
        return true;
    }
};