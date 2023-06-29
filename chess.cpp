#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<climits>

using namespace std ;

int main()
{
    int test ; cin >>test ; 
    
    for(int t =0 ; t<= test; t++)
    {
        int n,m;  cin >>n>>m ;
        int sx,sy,dx,dy ; cin >>sx>>sy>>dx>>dy ;
        
        vector<vector<int>> grid(n,vector<int>(m,0)) ; 
        vector<vector<int>> vis(n,vector<int>(m,0)) ; 
        vis[sx-1][sy-1] = 1;
        
        int delrow[] = {2,2,-1,1,-2,-2,-1,1} ;
        int delcol[] = {1,-1,2,2,1,-1,-2,-2} ;
        
        queue<pair<pair<int,int>,int>> q ;
        
        q.push({{sx-1,sy-1},0}) ;
        
        int ans =INT_MAX ;
        int x,y,z ;
        
        while(!q.empty())
        {
          x = q.front().first.first ;
          y = q.front().first.second ;
          z = q.front().second ;
          q.pop() ;
          
          if(x == dx-1 && y == dy-1) 
          {
              ans = min(ans,z) ;
              continue ;
          }
          
          for(int i =0 ; i<8; i++)
          {
              int nrow = x + delrow[i] ; 
              int ncol = y + delcol[i] ; 
              
              if(nrow>=0 && nrow<n && ncol >=0 && ncol < m && !vis[nrow][ncol])
              {
                  vis[nrow][ncol] = 1;
                  q.push({{nrow,ncol},z+1}) ; 
              }
          }
        }
        
        cout <<"#"<<test<<" "<<ans <<endl; 
    }
}