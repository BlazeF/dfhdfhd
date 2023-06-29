#include<bits/stdc++.h>

using namespace std; 

bool isValid(int x, int y, int n, int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true ;
    }
    return false ;
}

bool left(int x)
{
    if(x == 1 || x == 3 || x==6 || x==7) return true ;
    return false ;
}
bool right(int x)
{
    if(x == 1 || x == 3 || x==4 || x==5) return true ;
    return false ;
}
bool up(int x)
{
    if(x == 1 || x == 2 || x==4 || x==7) return true ;
    return false ;
}
bool down(int x)
{
    if(x == 1 || x == 2 || x==6 || x==5) return true ;
    return false ;
}

int solve(int sr, int sc, int l,  vector<vector<int>> &vis, vector<vector<int>> &grid )
{
    int ans =0;
    vis[sr][sc] = 1;
    int n = grid.size() ; 
    int m = grid[0].size() ;
    
    queue<pair<pair<int,int>,int>> q ;
    
    q.push({{sr,sc},l}) ;
    int x,y,z ;
    while(!q.empty())
    {
           x = q.front().first.first ; 
           y = q.front().first.second ;
           z = q.front().second ;
           
           q.pop() ;
           if(z==0) continue ;
           ans++ ; 
           
           if(isValid(x,y-1,n,m) && left(grid[x][y]) && right(grid[x][y-1]) && !vis[x][y-1] )
           {
               
               vis[x][y-1] =1 ;
               q.push({{x,y-1},z-1}) ; 
           }
            if(isValid(x,y+1,n,m) && right(grid[x][y]) && left(grid[x][y+1]) && !vis[x][y+1] )
           {
               
               vis[x][y+1] =1 ;
               q.push({{x,y+1},z-1}) ; 
           }
            if(isValid(x-1,y,n,m) && up(grid[x][y]) && down(grid[x-1][y]) && !vis[x-1][y] )
           {
               
               vis[x-1][y] =1 ;
               q.push({{x-1,y},z-1}) ; 
           }
            if(isValid(x+1,y,n,m) && down(grid[x][y]) && up(grid[x+1][y]) && !vis[x+1][y] )
           {
                
               vis[x+1][y] =1 ;
               q.push({{x+1,y},z-1}) ; 
           }
    }
    return ans ;
}

int main()
{  int t; cin >>t; 
    while(t--)
    {
    int n, m ; cin >>n>>m ; 
    int sr, sc; cin >>sr>>sc ;
    int l ; cin >>l ;
    
    vector<vector<int>> grid(n, vector<int>(m,0)) ;
    vector<vector<int>> vis(n, vector<int>(m,0)) ;
    
    for(int i =0 ; i<n; i++)
    {
        for(int j =0 ; j<m; j++)
        {
            cin >> grid[i][j] ; 
        }
    }
    
    
    cout << solve(sr,sc,l,vis,grid)  << endl ;
    }
}