#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int R,G,B,N; cin>>R>>G>>B>>N;
    int count=0;
    for(int i=0;i<=N/R;i++){   //R
        for(int j=0;j<=(N-R*i)/G;j++){   //G
            int k=(N-(R*i+G*j))/B;
            if(N==R*i+G*j+B*k)count++;
        }
    }
    cout<<count;
    return 0;
}
