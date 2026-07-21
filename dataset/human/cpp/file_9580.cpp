#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>
#include<bitset>
using namespace std;

int main(){
    int N,M;
    char n[50][51],m[50][51];
    bool flag;
    cin >> N >> M;
    for(int i=0;i<N;i++)    cin >> n[i];
    for(int i=0;i<M;i++)    cin >> m[i]; 
    if(M>N) cout << "No\n";
    else{
        for(int y=0;y<=N-M;y++){
            for(int x=0;x<=N-M;x++){
                flag = true;
                for(int i=0;i<M;i++){
                    for(int j=0;j<M;j++){
                        if(n[y+i][x+j]!=m[i][j]){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)   break;
                }
                if(flag){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
