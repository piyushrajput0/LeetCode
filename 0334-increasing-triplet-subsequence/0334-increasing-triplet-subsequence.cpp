class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int max=INT_MAX;
        int min=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(min>=nums[i])
            {
                min=nums[i];
            }
            else if(max>=nums[i])
            {
                max=nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
        
    }
};