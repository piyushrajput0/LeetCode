class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left=0;
        int right=height.size()-1;
        int ans=0;
        while(left<right)
        {
            cout<<left<<" "<<right<<endl;
            int x=min(height[left],height[right])*(right-left);
            ans=max(ans,x);
            
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};