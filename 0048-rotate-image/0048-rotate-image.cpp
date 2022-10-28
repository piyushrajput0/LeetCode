class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<m;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m/2;j++)
            {
                swap(arr[i][j],arr[i][m-j-1]);
            }
        }
        cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
        
    }
};