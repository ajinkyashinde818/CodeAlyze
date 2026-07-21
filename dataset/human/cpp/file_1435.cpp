#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
int n;
int a[1005][1005];
int main(void){
    cin>>n;
    for(int k=2;k*(k-1)<=n*2;k++){
        if(k*(k-1)==n*2){
            cout<<"Yes\n";
            cout<<k<<endl;
            int p=1;
            for(int i=0;i<k-1;i++){
                for(int j=i;j<k-1;j++){
                    a[i][j]=p;
                    a[j+1][i]=p;
                    p++;
                }
            }
            for(int i=0;i<k;i++){
                cout<<k-1<<' ';
                for(int j=0;j<k-1;j++){
                    cout<<a[i][j];
                    if(j!=k-2)cout<<' ';
                }
                cout<<endl;
            }
            return 0;
        }
    }
    cout<<"No\n";
}
