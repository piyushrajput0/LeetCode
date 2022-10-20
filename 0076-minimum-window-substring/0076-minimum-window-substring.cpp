class Solution {
public:
    
    bool check(unordered_map<char,int> &mp1 ,unordered_map<char,int>&mp2)
    {
        for(auto x: mp1)
        {
            if(mp2.find(x.first)!=mp2.end())
            {
                if(mp2[x.first]>=mp1[x.first])
                {}
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string p) {
        
        int n=s.size();
        int  m=p.size();
        if(m>n)
        {
            return "";
        }
        
        unordered_map<char,int>pat;
        for(int i=0;i<m;i++)
        {
            pat[p[i]]++;
            
        }
        int i=0;
        int j=0;
        int ans=INT_MAX;
        unordered_map<char,int>search;
        string str="";
        while(i<n)
        {
            
                if(pat.find(s[i])!=pat.end())
                  search[s[i]]++;
               
            
            if(check(pat,search))
            {
                // cout<<s[i]<<endl;
                while(j<n)
                {
                    if(ans>i-j+1)
                    {
                        ans=i-j+1;
                        str=s.substr(j,ans);
                        cout<<i<<" "<<j<<endl;;
                    }
                    
                if(pat.find(s[j])!=pat.end() && search[s[j]]>pat[s[j]])
                  search[s[j]]--;
                else if(pat.find(s[j])!=pat.end() && search[s[j]]==pat[s[j]])
                {
                    cout<<"endl"<<endl;
                    break;
                    
                }
                    
                    j++;
                    // cout<<"endl"<<endl;
                }
                
                
                // search[s[--j]]++;
                
            }
            i++;
            
        }
         
        return str;
    }
};