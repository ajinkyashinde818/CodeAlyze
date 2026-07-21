#include <stdio.h>
int pm(int n,int *l){
    int i,j,p=0,c=n-1,target[n-1];

    for(i=0;i<n-1;i++){target[i]=i+2;}
    for(i=0;i<n-1;i++){
        if (!target[i]){continue;}
        for(j=i;j<n-1;j=j+i+2){
            if (!target[j]){continue;}
            if (j!=i && target[j]%target[i]==0){target[j]=0;c--;}
        }
    }
    for(i=0;i<n-1;i++){
        if(target[i]){l[p]=target[i];p++;}
    } 
    return p;
} 

int main(void){
    int i,j,p,n=0,idx=0,l[110000];long int s,o[50];
    p=pm(110000,l);

    while(1){
        s=0;
        scanf("%d",&j);
        if(j==0){break;}
        for(i=0;i<j;i++){
            s+=l[i];
        }
        o[n]=s;
        n++;
    }
    for(i=0;i<n;i++){printf("%ld\n",o[i]);}
}
