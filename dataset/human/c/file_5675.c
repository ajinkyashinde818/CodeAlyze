#include <stdio.h>
#define MIN -1e9

int Maxmum(int a,int b){
    return ( (a>b) ? a : b );
}

int Minimum(int a,int b){
    return ((a<b) ? a : b); 
}
int main(){
    int t;
    scanf("%d",&t);
    int maxtmp,mintmp;
    int r[t];
    for(int i=0; i<t; i++) scanf("%d",&r[i]);

    mintmp = r[0];
    maxtmp = MIN;

    for(int i=1; i<t; i++){
        maxtmp = Maxmum(maxtmp,r[i]-mintmp);
        mintmp = Minimum(mintmp,r[i]);
    }

    printf("%d\n",maxtmp);

    return 0;
}
