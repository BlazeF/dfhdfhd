#include<bits/stdc++.h>

using namespace std ;

void solve(vector<int> &vis, vector<int> &arr, int &ans, int p1, int p2 )
{
    if(p1 ==p2)
    {
        ans = max(p1,ans) ;
        
    }
    
    for(int i = 0; i<arr.size() ; i++)
    {
        if(!vis[i])
        {
        vis[i] = 1 ;
         solve(vis,arr,ans,p1 + arr[i], p2) ;
         
         solve(vis,arr,ans,p1, p2 + arr[i]) ;
         vis[i] = 0 ; 
        }
    }
}

int main()
{
    int t ;cin >>t ;
    
    while(t--)
    {
        int n ;cin >>n ;
        vector<int> arr(n,0) ; 
        for(int i=0; i<n ; i++)
        {
            cin >>arr[i] ;
        }
        vector<int> vis(n,0) ;
        
        int ans = 0 ; 
        
        solve(vis,arr,ans,0,0) ; 
        cout << ans << endl ;
    }
}