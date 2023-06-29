#include<bits/stdc++.h>

using namespace std;

bool bipartite(int node, vector<int> adj[], vector<int> &color,int parent )
{
    for(auto it : adj[node] )
    {
        if(color[it] ==-1 )
        {
            color[it] = 1- color[node] ;
            if(!bipartite(it,adj,color,color[node])) return false ;
        }
        else
        {
            if(color[it] == color[node]) return false ;
        }
    }
    return true ;
}

int main()
{
    int V, E;
    V = 4 , E = 8;
    vector<int> adj[V];
    adj[0] = {1,3};
    adj[1] = {0,2};
    adj[2] = {1,3};
    adj[3] = {0,2};
    
    vector<int> color(4,-1) ;
    
    for(int i =0 ; i<V; i++)
    {
        if(color[i] == -1)
        {
            color[i] =0 ; 
            if(!bipartite(i,adj,color,-1))
            {
                cout << "-1" << endl ;
                return 0; 
            }
        }
    }
    for(int i =0 ; i<V; i++)
    {
        if(color[i] !=0)
        {
            cout << i << " " ;
        }
    }
    
}