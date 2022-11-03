class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        
        
        unordered_map<string,int>repeat;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i][0]==words[i][1])
            {
                repeat[words[i]]++;
            }
            else
            {
                mp[words[i]]++;
            }
        }
        unordered_map<string,int>mp2;
        for(int i=0;i<words.size();i++)
        {
            
            if(mp.find(words[i])!=mp.end())
            {
                
                string str=words[i];
                
                    reverse(str.begin(),str.end());
                
                if(mp.find(str)!=mp.end())
                {
                    
                    mp2.insert({words[i],min(mp[words[i]],mp[str])*2});
                    // cout<<words[i]<<" "<<str<<" : "<<mp[words[i]]<<endl;
                    mp.erase(str);
                    
                }
                
                    mp.erase(words[i]);
                
            }
            
        }
        int mx=INT_MAX;
        string str="";
        for(auto x:repeat)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second%2==1 && mx>(x.second))
            {
                 mx=x.second;
                str=x.first;
            }
        }
        if(mx==INT_MAX)
        {
            mx=0;
        }
        mx=mx*2;
        if(str.size()!=0)
        {
            // cout<<str<<endl;
            repeat.erase(str);
        }
        
        int mx2=0;
        
        for(auto x:repeat)
        {
            // cout<<x.first<<" "<<x.second<<endl;
            if(x.second!=1 && x.second%2==1)
            {
                 mx2+=(x.second-1)*2;
                
            }
            else if(x.second%2==0)
            {
                mx2+=x.second*2;
            }
        }
        
        
      
        // aa bb dd dd cc cc cc dd  dd bb aa
        int len=0;
        cout<<mp.size()<<endl;
        for(auto x:mp2)
        {
            
            len+=(x.second)*2;
            // cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<len<<" "<<mx<<" "<<mx2<<endl<<endl;
        int ans1= len+mx+mx2;
        return ans1;
    }
    
};