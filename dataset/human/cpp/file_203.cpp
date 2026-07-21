#include <bits/stdc++.h>
using namespace std;
int main() {
    long R,G,B,N;
    cin>>R>>G>>B>>N;
    long ans=0;
    for(int i=0;i<=N/R;i++){
        for(int j=0;j<=(N-R*i)/G;j++){
            if((N-R*i-G*j)%B==0) ans++;
        }
    }
    cout<<ans<<endl;
}
