#include<algorithm>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<map>
using namespace std;

int main(){
//srandom((unsigned long)time(NULL));

int n,m;
cin>>n>>m;
string a[n],b[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<m;i++){
    cin>>b[i];
}


//ai  3224----a[i][j]
//an  1211----a[n][n]
bool exist=false;

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
if(i+m-1>=n) continue;

    bool match=true;
    for(int y=0;y<m;y++){
        for(int x=0;x<m;x++){
            if(a[i+y][j+x]!=b[y][x])match=false;
        }
    }
    if(match) exist=true;


    }
}

if(exist)
    cout<<"Yes"<<endl;
else
    cout<<"No"<<endl;


return 0;
}
