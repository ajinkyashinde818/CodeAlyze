#include <stdio.h>
#include <stdlib.h>
int desc(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}
int min(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    int N;
    int A[100000];
    int i;
    int m;
    m=10000;
    int n;
    n=-10000;
    int M[100000];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(A[i]<0){
            M[i]=-1;
        }else{
            M[i]=1;
        }
        m=min(m,A[i]);
        n=max(n,A[i]);
    }
    int ans;
    ans=0;
    for(i=0;i<N;i++){
        ans=ans+A[i]*M[i];
    }
    if(m>0){
        ans=ans-2*m;
    }
    if(n<0){
        ans=ans+2*n;
    }
    printf("%d\n",ans);
    qsort(A,N,sizeof(*A),desc);
    int j;
    if(m<0){
        for(i=N-1;i>=0;i--){
            if(A[i-1]>=0||i==0){
                j=i;
                goto next;
            }
            printf("%d %d\n",A[0],A[i]);
            A[0]=A[0]-A[i];
        }
        next:
        for(i=0;i<j-1;i++){
            printf("%d %d\n",A[j],A[i]);
            A[j]=A[j]-A[i];
        }
        if(j>0){
            printf("%d %d\n",A[j-1],A[j]);
        }
    }
    if(m>=0){
        for(i=0;i<N-2;i++){
            printf("%d %d\n",A[N-1],A[i]);
            A[N-1]=A[N-1]-A[i];
        }
        printf("%d %d\n",A[N-2],A[N-1]);
    }
}
