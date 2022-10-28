class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        
        
        int n=nums.size();
        
        if(n==1)
        {
            return true;
        }
        vector<int>v(n,0);
        v[n-1]=1;
        
        for(int i=n-2;i>=0;i--)
        {
            int x=nums[i];
            for(int j=1;j<=x && i+j<n;j++)
            {
                if(v[i+j]==1)
                {
                    // cout<<i<<" "<<i+j<<endl;
                    v[i]=1;
                    break;
                }
            }
        }
        
        return v[0];
         
    }
};