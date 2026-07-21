#include <stdio.h>

int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！

    int n;
    int a[100],b[100];
    int count=0;
    int max=0;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            count++;
            if(count>max){
                max=count;
            }
        }else{
            
            count=0;
        }
    }
    
    if(max>=3){
        puts("Yes");
    }else{
        puts("No");
    }

 
    
    return 0;
}
