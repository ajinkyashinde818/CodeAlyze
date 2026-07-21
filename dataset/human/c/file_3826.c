#include<stdio.h>
int main()
{
    int A,B,i,Atmp,Btmp;
    int a[100000]={0},b[100000]={0},c[100000]={0};
    double n=1;
    scanf("%d %d",&A,&B);
    Atmp=A;
    Btmp=B;
    for(i=2;i<100000;i++){
        if(A%i==0){
            a[i]+=1;
            A=A/i;
            i--;
        }
    }
    for(i=2;i<100000;i++){
        if(B%i==0){
            b[i]+=1;
            B=B/i;
            i--;
        }
    }
    for(i=2;i<100000;i++){
        if(a[i]!=0 && b[i]!=0){
            a[i]--;
            b[i]--;
            c[i]++;
            i--;
        }
    }
    for(i=2;i<100000;i++){
        if(c[i]!=0){
            n*=i;
            c[i]--;
            i--;
        }
    }
    //printf("%d\n",n);
    Atmp=Atmp/n;
    Btmp=Btmp/n;
    n=n*Atmp*Btmp;
    printf("%.0f\n",n);
    return 0;
}
