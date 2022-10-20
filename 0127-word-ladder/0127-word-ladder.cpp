class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int n=wordList.size();
        
        int p=wordList[0].size();
        int flag=false;
    for(int i=0;i<n;i++)
    {
        if(wordList[i]==endWord)
        {
            flag=true;
        }
    }
        
        if(flag==false)
        {
            return 0;
        }
        
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[wordList[i]]++;
        }
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        int ans=INT_MAX;
         unordered_map<string,int>dump=mp;
        while(!q.empty())
        {
            int cn=q.front().second;
            string str=q.front().first;
            q.pop();
           
            for(int i=0;i<p;i++)
            {
                for(int j=0;j<=26;j++)
                {
                    string temp=str;
                    temp[i]='a'+j;
                    if(dump.find(temp)!=dump.end())
                    {
                        
                        dump[temp]--;
                        if(dump[temp]==0)
                        {
                            dump.erase(temp);
                        }
                        q.push({temp,cn+1});
                    }
                    if(temp==endWord)
                    {
                        ans=min(ans,cn+1);
                    }
                    
                }
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
                           
        
    }
};