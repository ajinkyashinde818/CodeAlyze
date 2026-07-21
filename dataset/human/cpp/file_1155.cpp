#include<bits/stdc++.h>
using namespace std;
long long count( long long S[], long long m, long long n ) 
{ 
    long long i, j, x, y; 
    long long table[n + 1][m]; 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
  
            y = (j >= 1) ? table[i][j - 1] : 0; 
  
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 
} 
int main()
{
    long long n;
    long long arr[3];
    cin>>arr[0]>>arr[1]>>arr[2]>>n;
    cout<<count(arr,3,n)<<endl;
    return 0;
    
}
