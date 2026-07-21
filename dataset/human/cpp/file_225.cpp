#include<bits/stdc++.h>
using namespace std;
int main(){
    double R,G,B,N;cin>>R>>G>>B>>N;
    int ans=0;
    double a=0;
    for (int i = 0; i <= N; i++)
    {
        /* code */
        for (int j = 0; j <= N; j++)
        {
            /* code */
           a=(N-R*i-G*j)/B;
          
            if (fmod(a,1.0)==0.0&&a>=0.0)
            {
                /* code */
                ans++;
            }
            
        }
        
    }
    
    
    cout<<ans<<endl;
    }
