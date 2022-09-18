class Solution {
public:
    
    
    vector<int> help1(vector<int>&height)
    {
        int n=height.size();
        int maxi=height[0];
        vector<int>v(n,0);
        for(int i=1;i<n;i++)
        {
            if(height[i]<maxi)
            {
                v[i]=maxi;
            }
            else
            {
                v[i]=height[i];
                maxi=height[i];
            }
        }
        return v;
    }
    
    vector<int> help2(vector<int>&height)
    {
        int n=height.size();
        int maxi=height[n-1];
        vector<int>v(n,n-1);
        for(int i=n-2;i>=0;i--)
        {
            if(height[i]<maxi)
            {
                v[i]=maxi;
            }
            else
            {
                v[i]=height[i];
                maxi=height[i];
            }
        }
        return v;
    }
    
    int trap(vector<int>& height) {
        
        vector<int>left=help1(height);
        vector<int>right=help2(height);
        int n=height.size();
        
        int water=0;
        for(int i=1;i<n-1;i++)
        {
            water+=min(left[i],right[i])- height[i];
            
        }
        return water;
    
        
    }
}; 