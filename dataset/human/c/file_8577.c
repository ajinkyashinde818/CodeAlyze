#include<stdio.h>
#include<string.h>
int t[100009];
int main(){
    int a;
    scanf("%d",&a);
    int o = 0;
    for(int i = 0;i<a;i++){
        scanf("%d",&t[i]);
        if(t[i]==2) o = 1;
    }
    if(o==0) printf("-1\n");
    else{
    int k = 0;
	int j = 0;
      while(1){
        if(k==a){
            printf("-1\n");
            break;
        }
        if(t[j]!=2){
            k++;
            j = t[j]-1;
			
        }
        else if(t[j]==2){
            printf("%d\n",k+1);
            break;
        }
       }
    }

return 0;

}
