class Solution {
public:
    vector<string>v;
    void help(string s,vector<string>&wordDict,string ans)
    {
        if(s.size()==0)
        {
            
            v.push_back(ans.substr(0,ans.size()-1));
            return ;
        }
        
        for(int j=0;j<wordDict.size();j++)
        {
            int size=wordDict[j].size();
            if(wordDict[j]==s.substr(0,size))
            {
                string temp=ans;
                ans+=wordDict[j]+" ";
                
                help(s.substr(size),wordDict,ans);
                ans=temp;
                
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        
        help(s,wordDict,"");
        return v;
    }
};