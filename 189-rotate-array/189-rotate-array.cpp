class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
       int n=nums.size();
         if(nums.size()==k)
        {
            return ;
        }
        else if(nums.size()<k)
        {
            k=k%nums.size();
        }
        
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end());
        
    }
};
