// 5
// 0 1 1 0 1
// 1 0 0 1 0
// 1 0 0 0 1
// 0 1 0 1 1
// 1 0 1 1 1
// 4 4 2 4

#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int t; cin >>t ;
    
    while(t--)
    {
        int n ;cin>>n ;
        
        vector<vector<int>> grid(n,vector<int>(n,0)) ;
        vector<vector<int>> vis(n,vector<int>(n,0)) ;
        
        for(int i=0 ; i<n; i++)
        {
            for(int j =0 ;j<n; j++)
            {
                cin >> grid[i][j] ;
            }
        }
        
        int sx, sy, dx, dy ; cin>>sx>>sy>>dx>>dy ;
        
        vis[sx][sy] =1 ;
        
        int delrow[] = {1,0,-1,0} ; int delcol[] = {0,1,0,-1} ;
        
        queue<pair<pair<int,int>,int>> q; 
        q.push({{sx,sy},0}) ;
        
        int ans =INT_MIN;
        int x,y,z ;
        while(!q.empty())
        {
            x = q.front().first.first ;
            y = q.front().first.second ;
            z = q.front().second ;
            q.pop() ;
            if(x == dx && y == dy)
            {
                ans = max(ans,z) ;
            }
            for(int i =0; i<4 ;i++)
            {
                int nrow = x + delrow[i] ;
                int ncol = y + delcol[i] ; 
                
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1; 
                    if(i==0 || i ==2)
                    {
                        q.push({{nrow,ncol}, z+1}) ;
                    }
                    else
                    {
                        q.push({{nrow,ncol}, z}) ;
                    }
                }
            }
        }
        cout << ans ;
        
    }
}