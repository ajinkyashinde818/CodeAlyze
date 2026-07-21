#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(){
    int q;cin>>q;
    for(int i=0;i<q;i++){
        char s[10];
        scanf("%s",s);
        long long t;
        sscanf(s, "%llx", &t);
        int sign=(t>>31&1)? -1 : 1;
        t &=~(1LL<<31);
        if(sign==-1)cout << "-";
        char ans[100];
        sprintf(ans,"%.20lf",1.*t/(1<<7));
        int j;
        for(j=strlen(ans)-1;ans[j]=='0';j--){
            ans[j]=0;
        }
        if(ans[j]=='.')ans[j+1]='0',ans[j+2]=0;
        cout << ans << endl;
    }
}
