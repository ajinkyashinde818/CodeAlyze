#include <stdio.h>
int main(void){
    int k,s,ans=0;
    scanf("%d%d",&k,&s);
    for (int x=0; x<=k; x++){
        int s2=s;
        s2-=x;
        if (s2>=0){
            for (int y=0; y<=k; y++){
                int s3=s2 ;
                s3-=y ;
                if (s3<=k && s3>=0){
                    ans++;
                }
            }
        }
    }
    printf ("%d\n",ans) ;
	return 0 ;
}
