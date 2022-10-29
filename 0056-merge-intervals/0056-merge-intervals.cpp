class Solution {
public:
    
    static bool cmp(vector<int>a,vector<int>b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        // stack<vector<int>>s;
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        ans.push_back(intervals[0]);
        int len=0;
        for(int i=0;i<n;i++)
        {
            
            if(ans[len][1]>=intervals[i][0])
            {
               
                
                ans[len][1]=max(ans[len][1],intervals[i][1]);
                // s.push(temp);
            
            }
            else
            {
                ans.push_back(intervals[i]);
                len++;
            }
            
        }
        return ans;
        
    }
};