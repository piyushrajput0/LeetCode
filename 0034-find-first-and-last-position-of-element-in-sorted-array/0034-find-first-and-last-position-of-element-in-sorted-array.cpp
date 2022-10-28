class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>v;
        
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target )
            {
                if(mid==0 || nums[mid-1]!=target)
                {
                    v.push_back(mid);
                    break;
                }
                else
                {
                    high=mid-1;
                }
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        low=0;
        high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==target )
            {
                if(mid==nums.size()-1 || nums[mid+1]!=target)
                {
                    v.push_back(mid);
                    break;
                }
                else
                {
                    low=mid+1;
                }
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        if(v.size()==0)
        {
            return {-1,-1};
        }
        else
        {
            return v;
        }
    }
};