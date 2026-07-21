#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
long int a[200000];
int main(void){
    int n,m;
    cin>>n>>m;
    char a[100][100],b[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x=0;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(b[k][l]==a[i+k][j+l]){
                        x++;
                        if(x==m*m){
                            cout<<"Yes"<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
