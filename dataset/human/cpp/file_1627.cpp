#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;

int x[200000];
int y[200000];
int main() {
    //ios_base::sync_with_stdio(false);
    //cout<<fixed<<setprecision(20);
    int n;
    cin>>n;
    int k=0;
    while(k*(k+1)/2<n)k++;
    if(k*(k+1)/2!=n){
        cout<<"No";
        return 0;
    }
    cout<<"Yes"<<'\n'<<k+1<<'\n';
    int beg=0;

    for(int i=1;i<=k;i++){
        y[i]=y[i-1]+(k-i);
    }
    for(int i=0;i<k+1;i++){
        cout<<k<<" ";
        for(int j=0;j<i;j++){
            cout<<y[j]+i<<" ";
        }
        for(int j=i;j<k;j++){
            cout<<y[i]+j+1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
