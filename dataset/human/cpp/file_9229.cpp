#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int N,M;

char n[70][70],m[70][70];

bool check(int nx,int ny){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(n[nx+i][ny+j]!=m[i][j]) return false;
        }
    }
    return true;
}
int main(void){
    
    
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>n[i][j];
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            cin>>m[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(n[i][j]==m[0][0]){
                if(check(i,j)){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    
}
