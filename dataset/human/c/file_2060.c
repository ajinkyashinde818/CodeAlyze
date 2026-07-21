#include <stdio.h>
 
long w[100];
int m,n;
long minhaba=1500000L;
 
long meyasuhaba;
 
int okeruka(int haba){
        int i;
        int dan=0;
        int danhaba=0;
 
        for(i=0;i<n;i++){
                if(w[i]>haba)return 0;
                if(danhaba+w[i]>haba){
                        dan++;
                        danhaba=0;
                }
                danhaba+=w[i];
        }
        return dan<m ? 1 : 0;
}
 
main(){
        long i;
        int sum;
        long  head,tail;
        while(1){
                scanf("%d %d",&m,&n);
                if(m==0)break;
                for(i=0;i<n;i++)scanf("%ld",&w[i]);
                head=0;
                tail=1500000L;
                do{
                        //printf("head,tail %ld,%ld\n",head,tail);
                        i=(head+tail)/2;
                        if(okeruka(i))
                                tail=i-1;
                        else
                                head=i+1;
                }while(tail-head>=0);
                i--;
                while(!okeruka(i))i++;
                printf("%ld\n",i);
        }
 
        return 0;
}
