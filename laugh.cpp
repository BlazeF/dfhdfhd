#include<bits/stdc++.h>

using namespace std ; 

int main()
{
    int test; cin >>test ; 
    for(int t =0 ; t < test; t++)
    {
        int n,m; cin >>m>>n ;
        
        vector<vector<int>> grid(n,vector<int>(m,0)) ; 
        vector<vector<int>> vis(n,vector<int>(m,0)) ;
        for(int i =0 ; i< n;i++)
        {
            for(int j =0 ; j< m ;j++)
            {
                cin >> grid[i][j] ;
            }
        }
        int sr , sc ; cin >>sr>>sc ;
        
        int level =1 ; 
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{sr-1,sc-1},level}) ;
        vis[sr][sc] = 1 ;
        
        int delrow[] = {1,0,-1,0} ; int delcol[] = {0,1,0,-1};
        int ans = 0 ; 
        int x,y,l ;
        while(!q.empty())
        {
             
            x = q.front().first.first ; 
            y = q.front().first.second ;
            l = q.front().second ;
            ans = max(ans,l) ;
            q.pop() ;
            
            for(int i =0; i<4 ; i++)
            {
                int nrow = x + delrow[i] ; int ncol = y + delcol[i] ; 
                
                if(nrow >=0 && nrow <n && ncol>=0 && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] ==1)
                {
                    vis[nrow][ncol] = 1 ;
                    q.push({{nrow,ncol},l+1}) ; 
                    ans = max(ans,l) ;
                }
            }
        }
        cout <<"#"<<t+1 <<" " <<ans << endl ;
    }
}