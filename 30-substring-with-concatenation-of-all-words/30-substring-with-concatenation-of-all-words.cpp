class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        
        int n=words.size();
         int maxlen=words[0].size();
        
         vector<int>ans;
        cout<<n*maxlen<<" "<<s.size()<<endl;
        if(n*maxlen>s.size())
        {
            return ans;
        }
       
        unordered_map<string,int>mpofwords;
        for(int i=0;i<n;i++)
        {
            mpofwords[words[i]]++;
        }
        
       
        string str="";
        for(int i=0;i<=(s.size()-n);i++)
        {
            str+=s[i];
            
            if(str.size()==maxlen)
            {
                
                if(mpofwords.find(str)!=mpofwords.end())
                {
                    
                    string frwords="";
                    int rwords=1;
                    unordered_map<string,int>copyofmap=mpofwords;
                     copyofmap[str]--;
                    if(copyofmap[str]==0)
                    {
                        copyofmap.erase(str);
                    }
                    int flag=true;
                    if(copyofmap.size()==0)
                    {
                         ans.push_back(i-maxlen+1);
                        // str="";
                        // continue;
                        flag=false;
                            
                    }
                    if(flag)
                    for(int j=i+1;j<s.size();j++)
                    {
                        
                        frwords+=s[j];
                       
                        
                        if(frwords.size()==maxlen)
                        {
                            if(copyofmap.find(frwords)!=mpofwords.end())
                            {
                                    copyofmap[frwords]--;
                                    if(copyofmap[frwords]==0)
                                    {
                                        copyofmap.erase(frwords);
                                    }

                                   frwords="";
                            }
                            else
                            {
                                break;
                            }
                                
                                
                            
                        }
                        
                        
                        if(copyofmap.size()==0)
                        {
                           
                            ans.push_back(i-maxlen+1);
                            
                                break;
                            
                        }
                    }
                    
                    
                }
               
                    str=str.substr(1);
                
                  
               
                
                
            }
            
        }
        return ans;
    }
};