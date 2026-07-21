#include<stdio.h>
#include<stdlib.h>
int asc(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(void){
    int k,n;

    scanf("%d%d",&k,&n);

    int a[n];

    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

int dif[n];

dif[0] = a[0]+(k-a[n-1]);

for(int i = 1; i < n; i++){
    dif[i] = a[i] - a[i-1];
}

qsort(dif,n,sizeof(int),asc);
int ans = 0;
for(int i = 0; i < n-1; i++){
ans += dif[i];
}
printf("%d",ans);
return 0;
}
