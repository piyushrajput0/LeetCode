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
        int zero=0;
        int index=-1;
        int del=0;
        for(int i=n-2;i>=0;i--)
        {
            int x=nums[i];
            
            if(zero)
            {
                if(i+x>index)
                {
                    cout<<i<<endl;
                    del=1;
                }
            }
            
            if(nums[i]==0 && zero==0)
            {
                zero=1;
                index=i;
            }
            if(del)
            {
                zero=0;
                index=-1;
                del=0;
            }
        }

        if(zero==0)
        {
            return true;
        }
        return false;
         
    }
};