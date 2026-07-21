#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<vector>

using namespace std;

//全パターン平行移動して全点で等しいか調べる

int main() {
    int n,m;
    cin>>n>>m;

    const int nmax=50;
    char a[nmax][nmax], b[nmax][nmax];

    for(int y=0; y<n; y++) {
        for (int x=0; x<n; x++){
            cin>>a[y][x];
        }
    }
    for(int y=0; y<m; y++) {
        for (int x=0; x<m; x++){
            cin>>b[y][x];
        }
    }

    bool exist=false;
    //a(n*n)がb(m*m)を含むか判定
    for(int ly=0; ly<n; ly++){//bがn*n(a)のフィールドで(ly,lx)平行移動する
        for(int lx=0; lx<n; lx++){
            if(ly+m-1>n || lx+m-1>n)continue;//はみ出たらループ抜ける

            bool match=true;//(ly,lx)平行移動完了→m*mのどこかの点で!=があればfalseにするループ
            for(int y=0; y<m; y++){
                for(int x=0; x<m; x++){
                    if(a[ly+y][lx+x]!=b[y][x])match= false;
                }
            }
            if(match)exist=true;
        }
    }

    if(exist) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
