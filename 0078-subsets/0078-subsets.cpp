class Solution {
public:
    vector<vector<int>>ans;
    void help(vector<int>&nums,int idx)
    {
        if(idx==nums.size())
        {
            return ;
        }
        
        
            int n=ans.size();
            for(int j=0;j<n;j++)
            {
                vector<int>temp=ans[j];
                temp.push_back(nums[idx]);
                ans.push_back(temp);
            }
        help(nums,idx+1);
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        ans.push_back({});
        help(nums,0);
        return ans;
    }
};