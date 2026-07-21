#include <stdio.h>
int main(void)
{
int i,n,d1[101],d2[102];
scanf("%d", &n);
for(i=0;i<n;i++){
  scanf("%d%d", &d1[i], &d2[i]);
}
for(i=0;i<n-2;i++){
  if(d1[i]==d2[i] && d1[i+1] == d2[i+1] && d1[i+2]==d2[i+2]){
    printf("Yes");
    break;
  }
  else if(i+3==n) printf("No");
}
return 0;
}
