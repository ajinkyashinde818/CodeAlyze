#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int start[m],end[m];
    int startis[n],endis[n];
    for(int i=0; i<m; i++) scanf("%d %d",&start[i],&end[i]);
    for(int i=0; i<m; i++){
      if(start[i]==1)startis[end[i]-1]=1;
      if(end[i]==n)endis[start[i]-1]=1;
    }

    for(int i=0;i<m;i++){
      if(startis[i]==1 && endis[i]==1){
        printf("POSSIBLE\n");
        return 0;
      }
    }

    printf("IMPOSSIBLE\n");
    return 0;
}
