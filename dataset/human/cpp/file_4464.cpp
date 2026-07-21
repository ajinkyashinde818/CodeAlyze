#include<bits/stdc++.h>
using namespace std;
 
signed main(){
int a,b;
cin>>a>>b;
int d=a/2;
d++;
for(int c=0;c<a-1;c++){
    if(d>c)printf("0 ");
    else printf("%d ",b);
    }
    printf("%d\n",b);
}
