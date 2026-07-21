#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#include <vector>
#include <string.h>

int main(){
    
	
	bool a[524]={false},c[524]={false};
	int b[10024][3]={0};
	int i,j,x,y;
	int n,m,count=0;
	
	scanf("%d\n%d\n",&n,&m);
    while(n!=0||m!=0){
        if(n==0) break;
        count = 0;
        for(i=0;i<524;i++){
            a[i] = false;
            c[i] = false;
        }
        memset(b,0,sizeof(b));
	a[1] = true;
	c[1] = true;
	j=0;
	for(i=1;i<=m;i++){
		scanf("%d %d\n",&x,&y);
        //printf("%d %d\n",x,y);
		if(x==1){
			count++;
			a[y]=true;
			c[y] = true;
		}
    	
        if(y==1){
			count++;
			a[x]=true;
			c[x]=true;
		}
		b[i][1]=x;
		b[i][2]=y;
	}
    //printf("%d\n",count);
	for(j=1;j<=m;j++){
		if(a[b[j][1]]==true){
            if(c[b[j][2]]==false){
                count++;
				c[b[j][2]] = true;
			}
		}
        if(a[b[j][2]]==true){
            if(c[b[j][1]]==false){
                count++;
    			c[b[j][1]] = true;
			}
		}
        
	}
	//printf("%d\n",count);
	printf("%d\n",count);
    scanf("%d\n%d\n",&n,&m);
    }
	return 0;
}
