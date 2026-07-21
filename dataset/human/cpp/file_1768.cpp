#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int i,n,c,m;
    scanf("%d %d",&n,&m);
    int p[n+1],q[n+1],r[m];
    fill(r,r+m,0);
    fill(p,p+n+1,0);
    fill(q,q+n+1,0);

    for(i=0;i<m;i++){
        scanf("%d",&c);
        p[c]=1;
        r[i]=c;
    }
    for(i=m-1;i>=0;i--){
        if(!q[r[i]]){q[r[i]]=1;printf("%d\n",r[i]);}
    }
    for(i=1;i<n+1;i++){
        if(!p[i]){printf("%d\n",i);}
    }
    return 0;
}
