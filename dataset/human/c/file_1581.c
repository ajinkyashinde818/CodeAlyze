#include<stdio.h>
#include<string.h>
char ss[500000];
char s[500000];
int wei[500000];
int abs(int a){
	if (a<0) return -a;return a;
}
int main(){
	
	int l,n,sum,i;
	scanf("%s",s+1);
	s[0]='.'; 
	l=strlen(s);
	n=0;
	for (i=1;i<l;i++){
		if (s[i]!='x') {
			n++;
			ss[n]=s[i];
	        wei[n]=i;
		}
	}
	for (i=1;i<=n;i++) if (ss[i]!=ss[n-i+1]) {printf("-1\n");return 0;}
	sum=0;
	wei[0]=0;
	wei[n+1]=l;
	for (i=0;i<=(n-1)/2;i++) 
	sum=sum+abs(wei[i+1]-wei[i]-1-(-wei[n-i]+wei[n+1-i]-1));
	printf("%d\n",sum); 

}
