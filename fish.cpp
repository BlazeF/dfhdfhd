#include<bits/stdc++.h>

using namespace std ;

struct gate
{
   int pos ; int men ;    
};

int checkLeft(int x , vector<int> &vis)
{
    for(int i =x ; i >=1; i--)
    {
        if(!vis[i]) return i ;
    }
    return INT_MAX ;
}

int checkRight(int x, vector<int> &vis, int n)
{
    for(int i =x; i <=n; i++)
    {
        if(!vis[i]) return i ;
    }
    return INT_MAX ;
}

void solve(int a, int b, int c,int &ans, vector<int>&vis, gate g[], int curr,int sum,int n )
{
     if(sum > ans) return;
    if(g[curr].men ==0)
    {
        if(curr == a) {curr = b ;}
        else if(curr == b) {curr ==c ;}
        else 
        {
            ans = min(ans,sum) ;
            return ;
        }
    }
    
    int left = checkLeft(g[curr].pos,vis) ;
    int right = checkRight(g[curr].pos,vis,n) ;
    
    int lengthleft = abs(g[curr].pos -left) +1 ;
    int lengthright = abs(right - g[curr].pos) + 1;
    
    bool goleft = true ; bool goright = true ;
    
    if(lengthleft > lengthright)
    {
        goleft = false ;
    }
    if(lengthleft < lengthright)
    {
        goright = false ;
    }
    
    if(goright)
    {
        vis[right] =1 ;
        g[curr].men-- ;
        solve(a,b,c,ans,vis,g,curr,sum + lengthright,n) ;
        vis[right] = 0 ;
        g[curr].men++ ;
    }

    if(goleft)
    {
        vis[left] =1 ;
        g[curr].men-- ;
        solve(a,b,c,ans,vis,g,curr,sum + lengthleft,n) ;
        vis[left] = 0 ;
        g[curr].men++ ;
    }
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
    int n ; cin >>n ;
    gate g[3] ;
    
    for(int i =0; i<3; i++)
    {
        int x, y ;
        cin >>x >> y ;
        g[i].pos =x ; g[i].men = y ;
    }
    vector<int>vis(n+1,0) ;
    
    int ans =INT_MAX ;
    
    solve(0,1,2,ans,vis,g,0,0,n) ; 
    solve(0,2,1,ans,vis,g,0,0,n) ;
    solve(1,0,2,ans,vis,g,1,0,n) ;
    solve(1,2,0,ans,vis,g,1,0,n) ;
    solve(2,0,1,ans,vis,g,2,0,n) ;
    solve(2,1,0,ans,vis,g,2,0,n) ;
    
    cout<< ans << endl ;
    }
}