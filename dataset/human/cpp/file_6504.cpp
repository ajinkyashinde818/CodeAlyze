#include<stdio.h>
#include<string>
#include<string.h>
#include<utility>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<bitset>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int n;
    ll mod=1000000007;
    char s[200005]={};
    scanf("%d%s",&n,s);
    int left=0;
    int right=0;
    int rrem=0;
    ll ans=1;
    for(int i=1;i<=n;i++)ans=ans*i%mod;
    if(s[0]=='W' || s[2*n-1]=='W'){
        printf("0\n");
        return 0;
    }
    REP(i,n*2){
        if(i%2==0){
            if(s[i]=='B'){
                right++;
                rrem++;
            }
            else if(s[i]=='W'){
                left++;
                if(rrem>0){
                    ans=ans*rrem%mod;
                    rrem--;
                }
                else{
                    printf("0\n");
                    return 0;
                }
            }
        }
        else if(i%2==1){
            if(s[i]=='W'){
                right++;
                rrem++;
            }
            else if(s[i]=='B'){
                left++;
                if(rrem>0){
                    ans=ans*rrem%mod;
                    rrem--;
                }
                else{
                    printf("0\n");
                    return 0;
                }
            }
        }
    }
    if(left!=right){
        printf("0\n");
        return 0;
    }
    printf("%lld\n",ans);
    return 0;
}
