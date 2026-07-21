#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
	int a,s,d,f,g,h,j,i,k;
	scanf("%d %d",&a,&s);
	if(a==0){
		if(1989<=s) printf("H%d\n",s-1988);
		else if(1926<=s) printf("S%d\n",s-1925);
		else if(1912<=s) printf("T%d\n",s-1911);
		else if(1868<=s) printf("M%d\n",s-1867);
	}
	else if(a==4) printf("%d\n",1988+s);
	else if(a==3) printf("%d\n",1925+s);
	else if(a==2) printf("%d\n",1911+s);
	else if(a==1) printf("%d\n",1867+s);
	return 0;
}
