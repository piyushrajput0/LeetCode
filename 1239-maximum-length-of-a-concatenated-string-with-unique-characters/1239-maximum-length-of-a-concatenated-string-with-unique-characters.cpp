class Solution {
public:
    
    int finalans=0;
    void help(vector<string>&arr,int i, unordered_map<char,int>mp, int ans)
    {
        if(i==arr.size())
        {
            finalans=max(ans,finalans);
            return ;
        }
        
        int flag=1;
       
        unordered_map<char,int>temp=mp;
            for(int k=0;k<arr[i].size();k++)
            {
                if(temp.find(arr[i][k])!=temp.end())
                {
                    flag=0;
                    break;
                }
                temp[arr[i][k]]++;
            }
        
        if(flag)
        {
            help(arr,i+1,temp,ans+arr[i].size());
            
        }
        help(arr,i+1,mp,ans);
    }
    int maxLength(vector<string>& arr) {
        unordered_map<char,int>mp;
        
        help(arr,0,mp,0);
        return finalans;
    
    }
};