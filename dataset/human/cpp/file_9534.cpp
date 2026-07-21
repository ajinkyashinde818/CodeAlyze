#include <iostream>
using namespace std;

int main(){
    bool origin[50][50],copy[50][50];
    int n,m;
    cin>>n>>m;
    for(int x=0;x<n;++x){
        for(int y=0;y<n;++y){
            char ch;
            cin>>ch;
            if(ch=='#'){
             origin[y][x]=true;   
            }else{
             origin[y][x]=false;   
            }
        }
    }
    for(int x=0;x<m;++x){
        for(int y=0;y<m;++y){
            char ch;
            cin>>ch;
            if(ch=='#'){
             copy[y][x]=true;   
            }else{
             copy[y][x]=false;   
            }
        }
    }
    
    for(int x=0;x==0||x<n-m;++x){
        for(int y=0;y==0||y<n-m;++y){
            bool flag=false;
            for(int xx=0;xx<m;++xx){
                  for(int yy=0;yy<m;++yy){
                      if(origin[y+yy][x+xx]!=copy[yy][xx]){
                        flag=true;   
                      }
                      if(flag)break;
                  }
                if(flag)break;
            }
            if(!flag){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
