#include <stdio.h>
#include <stdlib.h>

int main(void){
        int n;
        int i=scanf("%d",&n);
        if(i<1){
                printf("error");
                exit(1);
        }
        int l[n];
        long snuke[n];
        int e=0;
        for(int i=0;i<n;i++){
                e=scanf("%d",&l[i]);
                if(e<1){
                        printf("error");
                        exit(1);
                }
        }

        long sum=0;
        for(int i=0;i<n;i++){
                sum+=l[i];
                snuke[i]=sum;
        }

        long sub=0;
        long min=0;
        sub=2*snuke[0]-sum;
        if(sub<0){
                sub=-sub;
        }
        min=sub;
        for(int i=0;i<n-1;i++){
                sub=2*snuke[i]-sum;
                if(sub<0){
                        sub=-sub;
                }
                if(sub<min){
                        min=sub;
                }
        }
        printf("%ld",min);
        return 0;
}
