#include <stdio.h>

int main(){
  int i,j,k,n,a[200005][3],m,start=0,temp,prev,pp,l;
  scanf("%d",&l);
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i][0]);
    a[i][1]=-1;
    a[i][2]=i+1;
  }
  a[n-1][2]=-1;
  while(a[start][2]!=-1){
    prev=-1;
    i=start;
    while(i!=-1){
      j=i;
      k=a[j][2];
      if(k==-1) break;
      i=a[k][2];
      a[j][2]=i;
      if(a[j][0]>a[k][0]){
        if(prev==-1){
          start=k;
        }else{
          a[prev][2]=k;
        }
        temp=j;
        j=k;
        k=temp;
      }
      prev=j;
      while(k!=-1){
        if((j==-1)||(a[j][0]>a[k][0])){
          temp=a[k][1];
          a[k][1]=a[pp][1];
          a[pp][1]=k;
          pp=k;
          k=temp;
        }else{
          pp=j;
          j=a[pp][1];
        }
      }
    }
  }
  m=0;
  temp=a[start][0];
  for(i=a[start][1];i!=-1;i=a[i][1]){
    j=a[i][0]-temp;
    if(j>m) m=j;
    temp=a[i][0];
  }
  j=a[start][0]-temp+l;
  if(j>m) m=j;
  printf("%d",l-m);
  return(0);
}
