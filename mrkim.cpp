#include<bits/stdc++.h>

using namespace std ;

void solve(int sx, int sy, int dx, int dy, vector<int> &vis, vector<vector<int>> &customer, int path, int count, int &ans )
{
    if(count == customer.size())
    {
        ans = min(ans, abs(sx-dx) + abs(sy-dy) + path) ; 
        return ;
    }
    
    for(int i =0 ; i< customer.size() ; i++)
    {
        if(!vis[i])
        {
            vis[i] =1 ;
            solve(customer[i][0], customer[i][1] , dx,dy,vis, customer, path + abs(customer[i][0] -sx) + abs(customer[i][1] - sy), count+1, ans) ; 
            vis[i] =0 ; 
        }
    }
}

int main()
{
    int t ; cin >>t ;
    for(int test =1 ;test<=t ; test++)
    {
        int n; cin >>n ; 
        vector<vector<int>> customer(n,vector<int>(2,0)) ; 
        int sx,sy,dx,dy; 
        vector<int> vis(n,0) ;
        
        cin >>sx>>sy>>dx>>dy ;
        
        for(int i =0 ;i < n ;i++)
        {
            cin >>customer[i][0] >>customer[i][1] ; 
        }
        
        int ans = INT_MAX ;
        
        solve(sx,sy,dx,dy,vis,customer,0,0,ans) ; 
        cout <<"#" <<test<<" "<<ans << endl ;
    }
}