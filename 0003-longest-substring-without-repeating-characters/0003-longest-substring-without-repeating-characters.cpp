class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int j=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                // cout<<i<<" "<<j<<endl;
                if(ans<(mp.size()))
                {
                    ans=mp.size();
                }
                
                while(mp.find(s[i])!=mp.end() && j<s.size())
                {
                    mp[s[j]]--;
                    if(mp[s[j]]==0)
                    {
                        mp.erase(s[j]);
                    }
                    j++;
                }
                mp[s[i]]++;
            }
            else
            {
                mp[s[i]]++;
                
            }
        }
        
        if(ans<(mp.size()))
                {
                    ans=mp.size();
                }
                
        return ans;
        
        
        
    }
};