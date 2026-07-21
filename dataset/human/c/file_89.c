#include<stdio.h>

int main(){
	int r,g,b,n;
	int ri,gi,bi,c;
	int ans=0;
	scanf("%d %d %d %d",&r,&g,&b,&n);
	
	for(ri=0;ri*r<=n;ri++){
		for(gi=0;ri*r+gi*g<=n;gi++){
			if((n-(ri*r+gi*g))%b==0){
				ans++;
				continue;
			}
		}
	}
	printf("%d\n",ans);
					
	return 0;
}
