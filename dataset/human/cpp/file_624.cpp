#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R,G,B,N,res=0;cin>>R>>G>>B>>N;
    for (int i = 0; i < N/R+1; i++) {
        for (int j = 0; j < N/G+1; j++) {
            if((N-i*R-j*G)>=0 and (N-i*R-j*G)%B==0)res++;
        }
    }
    cout<<res;
}
