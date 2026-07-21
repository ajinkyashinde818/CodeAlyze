#include<stdio.h>
#include<string>
#include<utility>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<bitset>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int r,g,b,n;
    long long int ans=0;
    scanf("%d%d%d%d",&r,&g,&b,&n);
    REP(i,n/r+1){
        REP(j,n/g+1){
            if((n-r*i-g*j)%b==0 && n-r*i-g*j>=0){
                ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
