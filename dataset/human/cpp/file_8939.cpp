#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    char a[100][100],b[100][100];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            cin>>b[i][j];
        }
    }
    bool flag=false;
    for(int vy=0;vy<n;vy++) {
        for(int vx=0;vx<n;vx++) {
            if(vy+m-1>=n || vx+m-1>=n) continue;
            bool match=true;
            for(int y=0;y<m;y++) {
                for(int x=0;x<m;x++) {
                    if(a[vy+y][vx+x]!=b[y][x]) match=false;
                }
            }
            if(match) flag=true; 
        }
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;    
    return 0;
}
