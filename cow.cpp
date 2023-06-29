#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<climits>

using namespace std ;

bool possible(int x , vector<int> &arr, int k)
{
    int n =arr.size() ;
    int index =0 ;
    int cows =1 ;
    
    for(int i =0 ;i<n; i++)
    {
        if(arr[i]- arr[index] >=x)
        {
            index =i ;
            cows++ ;
            if(cows == k) {return true ;}
        }
    }
    return false ;
}

int main()
{
    int n,c ; cin >>n >> c ;
    
    vector<int> arr(n,0) ; 
    
    for(int i =0; i<n ;i++)
    {
        cin >> arr[i] ; 
    }
    sort(arr.begin(),arr.end()) ;
    
    
    int ans ; 
    for(int i =0 ; i < arr[n-1]; i++)
    {
        if(possible(i,arr,c)){ans = i ; }
        else
        { break ; }
    }
    
    
    cout << ans << endl ;
    
}