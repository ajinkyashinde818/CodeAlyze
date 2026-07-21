#include<stdio.h>
int main()
{
    int n;
    int a[100],b[100];
    int ans=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
       scanf("%d %d ", &a[i],&b[i]);
    }
    for(int i=0;i<n;i++){
       if(a[i] == b[i]){
         if(++ans ==3) break;
       } else ans=0;
    }
  
    // 出力
    if(ans!=3){
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    return 0;
}
