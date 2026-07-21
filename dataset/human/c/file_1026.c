/*????§?????????? by AZQ*/

#include <stdio.h>

int main(void){
    FILE *fp;
    fp = stdin;
    if(fp==NULL){
        printf("Error opening file\n");
        return 1;
    }
    
    char station[100];
    int station0[100];
    int key[100];
    int count;
    int i,j;
    while(1){
        fscanf(fp,"%d",&count);
        if(count==0){
            return 0;
        }
        for(i=0;i<count;i++){
            fscanf(fp,"%d",&key[i]);
        }
        fscanf(fp,"%s",station);
        i=0;
        j=0;
        while(station[i] != '\0'){
            station0[i]=(int)station[i];
            //printf("%d station:%d ",i,station0[i]);
            if(station0[i] <= 90 && station0[i]>=65){//65~90
                station0[i]=(station0[i]-65-key[j%count]+52)%52;

            }else if(station0[i]<=122 && station0[i]>=97){//97~122
                station0[i]=(station0[i]-71-key[j%count]+52)%52;
            }else{
                printf("error\n");
            }
            //printf("%d\n",station0[i]);
            if(station0[i]<26){
                station[i] = station0[i]+65;
            }else{
                station[i] = station0[i]+71;
            }
            j++;
            i++;
        }
        printf("%s\n",station);
    }
    
}
