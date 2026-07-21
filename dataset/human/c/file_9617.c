#include <stdio.h>

int main(void){
	int n,m,i,o;
	while(1){
        scanf("%d %d",&n,&m);
        if(!n)break;
        int score[100];
        char atari[100][9],a[1000][9];
        for(i=0;i<n;i++){
            scanf("%s %d",atari[i],&score[i]);
        }
        for(o=0;o<m;o++){
            scanf("%s",a[o]);
        }
        int ans=0;
        int j,k;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                for(k=7;k>=0&&atari[i][k]!='*';k--){
                    if(atari[i][k]!=a[j][k]){
                        break;
                    }
                }
                if(atari[i][k]=='*'||k<0){
                    ans+=score[i];
                   // break;
                }
            }
        }
		printf("%d\n",ans);
	}
	return 0;
}
