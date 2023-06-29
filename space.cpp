#include<bits/stdc++.h>

using namespace std ;

void updateMatrix(int x , int n, vector<vector<int>> &grid )
{
    for(int i =x ; i>x-5 && i>=0 ; i--)
    {
        for(int j =0 ; j< 5; j++)
        
       {
           if(grid[i][j] ==2)
           {
               grid[i][j] = 0 ; 
           }
        }
    }
}

int solve(int r, int c, vector<vector<int>> &grid,  int bomb)
{
    if(r<=0 || c<0 || c>=5)
    {
         
        return 0 ;
    }
    int answer =0 ;
    if(r > 0 &&  grid[r-1][c] != 2)
    {
        // vis[r-1][c] =1 ;
        if(grid[r-1][c] == 1)
        {
            answer = max(answer,1 +  solve(r-1,c,grid,bomb)) ;
        }
        else
        {
            answer = max(answer,solve(r-1,c,grid,bomb)) ;
        }
        // vis[r-1][c] = 0;
    }
    
    if(r > 0 && c >0 &&  grid[r-1][c-1] != 2)
    {
        // vis[r-1][c-1] =1 ;
        if(grid[r-1][c-1] == 1)
        {
            answer = max(answer,1 +  solve(r-1,c-1,grid,bomb)) ;
        }
        else
        {
            answer = max(answer,solve(r-1,c-1,grid,bomb)) ;
        }
        // vis[r-1][c-1] = 0;
    }
    
    if(r > 0 && c<4  && grid[r-1][c+1] != 2)
    {
        // vis[r-1][c+1] =1 ;
        if(grid[r-1][c+1] == 1)
        {
            answer = max(answer,1 +  solve(r-1,c+1,grid,bomb)) ;
        }
        else
        {
            answer = max(answer,solve(r-1,c+1,grid,bomb)) ;
        }
        // vis[r-1][c+1] = 0;
    }
    
    if(answer ==0 && bomb >0)
    {
        updateMatrix(r-1,grid.size()-1, grid) ;
        answer = solve(r,c,grid,bomb-1) ;
    }
    return answer ;
}

int main()
{
    int t ; cin >>t ;
    
    while(t--)
    {
        int r ; cin >>r ; 
        
        vector<vector<int>>grid(r+1, vector<int>(5,0)) ;
        // vector<vector<int>>vis(r, vector<int>(5,0)) ;
        
        for(int i =0; i<r; i++)
        {
            for(int j =0; j<5; j++)
            {
                cin >> grid[i][j] ;
            }
        }
        
        // int ans = INT_MIN ;
        
        int temp = solve(r+1,2,grid,1) ;
        
        cout << temp << endl ;
    }
}