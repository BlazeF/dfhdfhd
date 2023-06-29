#include<bits/stdc++.h>

using namespace std ;

void solve(int src, int cost, vector<int> &vis, vector<vector<int>> &map, int count, int &ans )
{
    if(count == vis.size() -1)
    {
        if(map[src][0] !=0)
        {
            ans = min(ans,cost + map[src][0]) ;
        }
        return ;
    }
    
    for(int i = 0 ; i< vis.size() ; i++)
    {
        if(!vis[i] && map[src][i] != 0)
        {
            vis[i] = 1 ; 
            solve(i,cost + map[src][i],vis, map, count+1, ans ) ; 
            vis[i] = 0; 
        }
    }
}

int main()
{
    int t ; cin >>t ;
    while(t--)
    {
        int n; cin >> n ;
        vector<vector<int>> map(n,vector<int>(n,0)) ;
        vector<int> vis(n,0) ; 
        for(int i =0 ; i< n;i++)
        {
            for(int j = 0 ; j<n;j++)
            {
                cin >> map[i][j] ;
            }
        }
        
        int ans = INT_MAX ; 
        // vis[0] =1 ;
        solve(0,0,vis,map,0,ans) ;
        
        cout << ans << endl ;
    }
}