#include<stdio.h>
#include<string.h>

int main(void)
{

	char c_str[100000];
	char r_str[200000];
	char l_str[200000];
	char ans[500000];
	
	unsigned long dir = 0;
	unsigned long num;
	unsigned long num_q2;
	unsigned long r_c = 0;
	unsigned long l_c = 0;

	char z;
	int i=0,j,k,l,x,y;	
	
	unsigned long c_len,r_len,l_len;
	
	scanf("%s",c_str);
	c_len = strlen(c_str);
	
	scanf("%lu",&num);

	num_q2 = num;
	
	while(i < num_q2){
		i++;
		scanf("%d",&x);
		num_q2 = num;

		if(x == 1){
			++dir;
		}else{
			scanf("%d %c",&y,&z);
			num_q2 = num;
			if(dir%2 == 0){
				if(y == 1){
					l_str[l_c]=z;
					l_c++;
				}else{
					r_str[r_c]=z;
					r_c++;
				}
			}else{
				if(y == 1){
					r_str[r_c]=z;
					r_c++;
				}else{
					l_str[l_c]=z;
					l_c++;
				}
			}
		}
	}
	
	c_len = strlen(c_str);
	r_len = strlen(r_str);
	l_len = strlen(l_str);
	
	if(dir%2 == 0){
		for(j=0;j<l_len;j++)
			ans[j]=l_str[l_len-1-j];
		for(k=0;k<c_len;k++)
			ans[k+l_len] = c_str[k];
		for(l=0;l<r_len;l++)
			ans[l+l_len+c_len] = r_str[l];
		printf("%s",ans);
	}else{
		for(j=0;j<r_len;j++)
			ans[j]=r_str[r_len-1-j];
		for(k=0;k<c_len;k++)
			ans[k+r_len]=c_str[c_len-1-k];
		for(l=0;l<l_len;l++)
			ans[l+r_len+c_len]=l_str[l];
		printf("%s",ans);
	}
	
	return 0;
}
