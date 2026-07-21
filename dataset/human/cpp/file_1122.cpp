#include<stdio.h>
#include<algorithm>
using std::sort;



int main(){
    int r,g,b,n;
    int ans=0;
    scanf("%d%d%d%d",&r,&g,&b,&n);
    for(int i=0;r*i<=n;i++){
        for(int j=0;r*i+g*j<=n;j++){
            int left=n-r*i-g*j;
            if(left%b==0)ans++;
        }
    }
    printf("%d\n",ans );
}
