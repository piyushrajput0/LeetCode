class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string ,int>mp;
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
       unordered_map<int, vector<string>>mp1;
        
        for(auto x:mp)
        {
            mp1[x.second].push_back(x.first);
        }
        
        priority_queue<pair<int,vector<string>>>pq;
        for(auto x:mp1)
        {
            pq.push(x);
        }
        
        vector<string>ans;
        while(k!=0)
        {
pair<int,vector<string>>temp1=pq.top();
            pq.pop();
            
            vector<string>temp=temp1.second;
            sort(temp.begin(),temp.end());
                 for(int i=0;i<temp.size();i++)
            {
                ans.push_back(temp[i]);
                    k--;
                     if(k==0)
                     {
                         return ans;
                     }
            }
            
            
            
           
            
            
        }
        
        return ans;
    }
};