#include <stdio.h>
#include <memory.h>
int main(void){
    int n,m,line[10000][2],line1[501],line2[501],sum;
    for(;sum=0,memset(line1,0,sizeof(line1)),memset(line2,0,sizeof(line2)),scanf("%d\n%d",&n,&m),n+m;){
        for(int i=0;i<m;i++){
            scanf("%d %d",&line[i][0],&line[i][1]);
            if(line[i][0] == 1){
                line1[line[i][1]]=line2[line[i][1]]=1;
                sum++;
            }
        }
        for(int i=0;i<m;i++){
            if(line[i][0] != 1 && line1[line[i][0]]==1 && line2[line[i][1]]==0){
                sum++;
                line2[line[i][1]]=1;
            }
            else if(line[i][0]!=1&&line1[line[i][1]]==1 && line2[line[i][0]]==0){
                sum++;
                line2[line[i][0]]=1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
