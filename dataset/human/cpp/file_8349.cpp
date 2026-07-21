#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<math.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define N (1000000000+7)
#define INF (ll)1e16
typedef pair<int,int> P;
typedef long long ll;
char board[60][60];
char board1[60][60];


int main(void){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cin>>board1[i][j];
        }
    }
    for(int i=1;i<=n-m+1;i++){
        for(int j=1;j<=n-m+1;j++){
            bool flag=false;
            for(int i1=i;i1<i+m;i1++){
                for(int j1=j;j1<j+m;j1++){
                    if(board[i1][j1]!=board1[i1-i+1][j1-j+1])flag=true;
                }
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
