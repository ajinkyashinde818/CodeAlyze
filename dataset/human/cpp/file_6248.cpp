/*
ID: taoxiaa1
PROG: concom
LANG: C++
*/
//URAL ID:248353QC
#include<bits/stdc++.h>
using namespace std;
//FILE *fin, *out;
//fin = fopen("money.fin", "r");
//out = fopen("money.out", "w");
//ofstream fout("money.out");
//ifstream fin("money.in");
long long dp1[100005], dp2[100005], t[100005], s[100005];
int main() {
    int n;
    long long c;
    scanf("%d%lld", &n, &c);
    for(int i = 1; i <= n; i++)
        scanf("%lld%lld", &s[i], &t[i]);
    s[0] = 0, t[0] = 0;
    for(int i = 1; i <= n; i++)
        dp1[i] = dp1[i - 1] + t[i];
    for(int i = n; i >= 1; i--) {
        if(i == n)
            dp2[i] = dp2[0] + t[i];
        else
            dp2[i] = dp2[i + 1] + t[i];
    }
    long long sum = 0,temp=0;
    for(int i = 1; i <= n; i++)
    {
        sum=max(sum,dp1[i]-s[i]);
        sum=max(dp2[i]-c+s[i]+temp,sum);
        temp=max(temp,dp1[i]-2*s[i]);
    }
    temp=0;
    for(int i=n;i>=1;i--){
        sum=max(sum,dp2[i]-c+s[i]);
        sum=max(sum,dp1[i]-s[i]+temp);
        temp=max(dp2[i]-2*c+2*s[i],temp);
    }
    printf("%lld\n", sum);
    return 0;
}
