#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
int n,d,x;
scanf("%d %d %d",&n,&d,&x);
int a[100];
int ans=x;
for(int i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
	int day=1;
	while(day<=d){
		day=day+a[i];
		ans=ans+1;
	}
}

printf("%d\n",ans);
}
