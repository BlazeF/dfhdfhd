#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int test ; cin >>test ;
    
    for(int t =1 ; t<= test ; t++)
    {
        int n,m; cin>>n >> m ; 
        
        vector<vector<int>> rare(m,vector<int>(2,0)) ;
        vector<vector<int>> grid(n,vector<int>(n,0)) ; 
        // vector<vector<int>> vis(n,vector<int>(n,0)) ;
        int count  = 0 ; 
  
        for(int i =0 ; i < m ; i++)
        {
            int a,b ; cin >>a >> b ; 
            rare[i][0] = a-1 ; rare[i][1] = b-1 ; 
        }
        for(int i = 0 ; i<n ; i++)
        {
            for(int j =0 ; j <n ;j++)
            {
                cin >> grid[i][j] ; 
            }
        }
        
      
        vector<int> maxi ;
        vector<int> ans ;
        int delrow[] = {1,0,-1,0} ; int delcol[] = {0,1,0,-1};
        
        queue<pair<pair<int,int>,int>>q ; 
        
        for(int i =0 ; i< n ; i++)
        {
            for(int j =0 ; j<n; j++)
            {
                vector<vector<int>> vis(n,vector<int>(n,0)) ;
                if(grid[i][j] ==1)
                {
                    q.push({{i,j},0}) ;
                    vis[i][j] =1 ;
                    
                    while(!q.empty())
                    {
                        int x,y,l ;
                        x = q.front().first.first ; 
                        y = q.front().first.second ; 
                        l = q.front().second ;
                        q.pop() ;
                        for(int f =0 ; f<4 ;f++)
                        {
                            int nrow = x + delrow[f] ; int ncol = y + delcol[f];
                            if(nrow>=0 && nrow < n && ncol>=0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                            {
                                vis[nrow][ncol] = 1 ;
                                q.push({{nrow,ncol},l+1}) ;
                                
                                for(int k =0 ; k<m ;k++)
                                {
                                    if(rare[k][0] == nrow && rare[k][1] == ncol)
                                    { 
                                        maxi.push_back(l+1) ; 
                                    }
                                }
                            }
                        }
                    }
                ans.push_back(*max_element(maxi.begin(),maxi.end())) ;
                maxi.clear() ;
                }
            }
        }
        cout<<"#"<<t<<" "<< *min_element(ans.begin(), ans.end()) << endl ;
    }
}