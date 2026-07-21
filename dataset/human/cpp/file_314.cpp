#include <bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b,n;
    int ans=0;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    for(int i=0;i<=(n/r);i++){
        for(int j=0;j<=(n/g);j++){
            if((n-r*i-g*j>=0) && (n-r*i-g*j)%b==0){ans++;}
        }
    }
    printf("%d\n",ans);
    return 0;

}
