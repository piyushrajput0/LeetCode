class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        sort(nums.begin(),nums.end());
        int cn=0;
        int n=nums.size();
        int i;
        int j;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            {
                 j=i;
                while(i<n && nums[i]==val)
                {
                    i++;
                    cn++;
                }
                break;
            }
            
        }
        
        while(i<n)
        {
            nums[j]=nums[i];
            j++;
            i++;
        }
        
        return n-cn;
        
    }
};