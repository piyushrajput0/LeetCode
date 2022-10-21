class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        map<pair<int,int>,map<double,int>>mp;
        for(int i=0;i<points.size();i++)
        {
            map<double,int>temp;
            // cout<<points[i][0]<<" "<<points[i][1]<<" : "<<endl;
            for(int j=0;j<points.size();j++)
            {
                if(i!=j)
                {   
                    double tn;
                    double a=(double(points[i][0]-points[j][0])/(double((points[i][1]-points[j][1]))));
                    if((points[i][1]-points[j][1])==0)
                    {
                        tn=INT_MAX;
                    }
                    else
                     tn=atan(a);
                    
                    // cout<<points[i][0]<<" "<<points[j][0]<<" : "<<a<<" "<<tn<<endl;
                    
                    temp[tn]++;
                    
                }
            }
            // cout<<endl;
            mp[{points[i][0],points[i][1]}]=temp;
        }
        
        int ans=INT_MIN;
        for(auto x:mp)
        {
            // cout<<x.first.first<<" "<<x.first.second<<" : "<<x.second<<endl;
            // cout<<x.first.first<<" "<<x.first.second<<" : "<<endl;
            for(auto y:x.second)
            {
                ans=max(ans,y.second);
                // // cout<<y.first<<" "<<y.second<<endl;
            }
            // cout<<endl;
        }
        if(ans==INT_MIN)
        {
            return 1;
        }
        return ans+1;
    }
};