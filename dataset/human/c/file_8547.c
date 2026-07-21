#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000
const int mod = INF+7;

void merge_sort(int *t1, int left, int right){    //アドレスが渡される
    if(left==right){
        ;
    }
    else{
        int n2=(right-left+1)/2;
        int n3=right-left+1-n2;
        int i=0,j=0,k=0;

        merge_sort(t1,left,left+n2-1);
        merge_sort(t1,left+n2,right);

        int t2[n2];
        int t3[n3];
        for(i=0;i<n2;i++){
          t2[i]=t1[left+i];
        }
        for(i=0;i<n3;i++){
          t3[i]=t1[left+n2+i];
        }

        for(i=0;i<n2+n3;i++){
            if(k==n3 || (j<n2 && t2[j]<t3[k])){
                t1[left+i]=t2[j];
                j++;
            }
            else{
                t1[left+i]=t3[k];
                k++;
            }
        }
    }
}

int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  int *A=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    scanf("%d",&A[i]);
  }

  merge_sort(A, 0, N-1);

  int sum=0;
  rep(i,N){
    if(A[i]<0){
      sum=sum-A[i];
    }
    else{
      sum=sum+A[i];
    }
  }

  if(A[0]<0 && A[N-1]>=0){
    printf("%d\n", sum);
  }
  else if(A[0]<0 && A[N-1]<0){
    printf("%d\n", sum+A[N-1]*2);
  }
  else if(A[0]>=0){
    printf("%d\n", sum-A[0]*2);
  }

  if(A[0]<0 && A[N-1]>=0){
    int bound;
    rep(i,N){
      if(A[i]>=0){
        bound=i;
        break;
      }
    }
    int temp=A[bound-1];
    srep(i, bound, N-1){
      printf("%d %d\n", temp, A[i]);
      temp=temp-A[i];
    }
    printf("%d %d\n", A[N-1], temp);
    temp=A[N-1]-temp;
    rep(i, bound-1){
      printf("%d %d\n", temp, A[i]);
      temp=temp-A[i];
    }
  }
  else if(A[0]<0 && A[N-1]<0){
    int temp=A[N-1];
    rrep(i,N-1){
      printf("%d %d\n", temp, A[i]);
      temp=temp-A[i];
    }
  }
  else if(A[0]>=0){
    int temp=A[0];
    srep(i,1,N-1){
      printf("%d %d\n", temp, A[i]);
      temp=temp-A[i];
    }
    printf("%d %d\n", A[N-1], temp);
  }

  return 0;


}
