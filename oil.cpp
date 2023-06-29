#include<bits/stdc++.h>

using namespace std ;

void solve(int i, vector<int> mine, vector<int> &vis, int c, int count,int &ans,int maxi, int mini,int sum )
{
    int n= mine.size() ;
 
    
    if(vis[i])
    {
        int newMin =min(sum,mini) ; 
        int newMax = max(sum,maxi) ;
        
        if(count == c -1)
        {
            ans = min(ans, newMax - newMin) ; 
        }
        return ;
    }
    
    vis[i] =1 ;
    int j = (i+1)%n ;
    
    solve(j,mine,vis,c,count,ans,maxi,mini,sum + mine[i]) ;
    
    int newMin = min(sum,mini) ;
    int newMax = max(sum,maxi) ;
    
    solve(j,mine,vis,c,count+1,ans,newMax,newMin,mine[i]) ;
    vis[i] =0 ;
    // return ;
}


int main()
{
    int t ; cin >>t ;
    while(t--)
    {
        int n,c ;
        cin >>c>>n;
        vector<int> mine(n,0) ;
        
        for(int i =0; i<n; i++)
        {
            cin >> mine[i] ; 
        }
        vector<int> vis(n,0) ;
        int ans= INT_MAX;
        
        for(int i = 0 ; i < n; i++)
      {  solve(i,mine,vis,c,0,ans,INT_MIN,INT_MAX,0) ;}
        cout << ans<< endl;
    }
}