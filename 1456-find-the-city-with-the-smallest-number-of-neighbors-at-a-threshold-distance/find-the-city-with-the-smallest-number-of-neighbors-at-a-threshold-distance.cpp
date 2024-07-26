class Solution {
public:
int findTheCity(int n, vector<vector<int>>& edges, int dt) 
{
    int ans=-1;
    vector<vector<int>>dis(n,vector<int>(n,1e5));
    
    for(auto it:edges)
    {
        dis[it[0]][it[1]]=it[2];
        dis[it[1]][it[0]]=it[2];
    }
    
    for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)
                    dis[i][j]=0;
            }
        }
    
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    int mn=INT_MAX,i=0;
    for(auto it:dis)
    {
        int c=-1;
        for(auto k:it)
        {
            if(k<=dt)
                ++c;
        }
        if(mn>=c)
        {
            mn=c;
            ans=i;
        }
        ++i;
    }
    return ans;
}
};