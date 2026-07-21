#include <iostream>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    
    const int nmax=50;
    char a[nmax][nmax],b[nmax][nmax];
    
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin >>a[y][x];
        }
    }
    for(int y=0;y<m;y++){
        for(int x=0;x<m;x++){
            cin >>b[y][x];
        }
    }
    
    bool exist=false;
    
    for(int ly=0;ly<n;ly++){
        for(int lx=0;lx<n;lx++){
            if(ly+m-1>=n||lx+m-1>=n) continue;
            
            bool match=true;
            for(int y=0;y<m;y++){
                for(int x=0;x<m;x++){
                    if(a[ly+y][lx+x]!=b[y][x])match=false;
                }
            }
            if(match)exist=true;
        }
    }
    
    if(exist)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
        
    return 0;    
}
