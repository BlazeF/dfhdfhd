#include<bits/stdc++.h>

using namespace std ;

void solve(int sr, vector<float> &answer, vector<vector<float>> &map, float p, int time, vector<vector<int>>&vis )
{
    if(time <=0)
    {
        answer[sr] += p;  
        return ;
       
    }
    for(int i =0; i< map.size() ; i++)
    {
        if(map[sr][i] && !vis[sr][i])
        {
            vis[sr][i] = 1 ;
            p *= map[sr][i] ;
            solve(i, answer,map,p,time-10, vis) ;
            p /= map[sr][i] ;
            vis[sr][i] = 0 ;
        }
    }
    // return ;
}

int main()
{
    int t ; cin >>t ;
    
    while(t--)
    {
        int V, E,time; cin >>V>>E>>time ;
        
        vector<vector<float>> map(V,vector<float>(V,0.0)) ;
        vector<vector<int>> vis(V,vector<int>(V,0)) ;
        for(int i =0; i<E; i++)
        {
            int x,y; float z ; cin >>x>>y>>z ;
            map[x-1][y-1] = z;
        }
        
        vector<float> answer(V,0.0) ;
        
        solve(0,answer,map,1.0,time, vis) ;
        int div ; float temp = 0.0;
        
        for(int i =0 ; i<V ; i++)
        {
            if(temp < answer[i])
            {
                temp = answer[i] ; 
                div = i ; 
            }
        }
        
        cout << div+1 <<" " << temp << endl ;
    }
}