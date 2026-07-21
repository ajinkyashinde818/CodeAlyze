#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>

typedef long long ll;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int min(int a,int b){
    if(a<b) return a;
    else return b;
}

/*qsort(array,num_of_index,sizeof(int),compare_int); */
 int compare_int(const void *a,const void *b){
     return *(int*) a - *(int *) b; 
 } 
 
int main(){
    int N;
    scanf("%d",&N);
    int Di[102],Dj[102];
    int f[102];
    for(int i=1;i<=N;i++){
        scanf("%d %d",Di+i,Dj+i);
        if(Di[i] == Dj[i])
            f[i] = 1;
        else
            f[i] = 0;
    }
    int len = 0,ans = 0;
    for(int i=1;i<=N;i++){
        if(f[i])
            len++;
        else
            len = 0;
        if(len >= 3)
            ans = 1;
    }
    if(ans)
        printf("Yes");
    else
        printf("No");
}
