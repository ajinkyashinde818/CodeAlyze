#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[55][55] , b[55][55];
int n , m ;

bool ok(int x,int y){

for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
        if( a[i+x][j+y] != b[i][j] )
            return 0;
return 1;
}

int main(){

cin>>n>>m;
for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
for(int i=0;i<m;i++)for(int j=0;j<m;j++)cin>>b[i][j];

for(int i=0;i+m<=n;i++)
    for(int j=0;j+m<=n;j++)
if( ok(i,j) ){
    cout<<"Yes"<<endl;return 0;
}
cout<<"No"<<endl;
return 0;
}
