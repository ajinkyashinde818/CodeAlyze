#include<stdio.h>
 int main(){
    int n;
     scanf("%d",&n);
      int Ar[2*n];
        for(int i=0;i<(2*n);i++){
             scanf("%d",&Ar[i]);
        }
        int count=0;
          int track=0;
        for(int i=0;i<(2*n);i=i+2){
            int k= count;
             if(Ar[i]==Ar[i+1]){
                 count++;
             }
             if(count>k){
                  track++;
             }
             else if(track>=3){
                 track=track;
             }
             else track=0;
        }
        if(track>=3) {
            printf("Yes");
        }
        else printf("No");

}
