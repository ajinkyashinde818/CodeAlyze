#include <stdio.h>
#include<stdlib.h>
#include <string.h> 


int main(void){
	int count=0;
	int i;
	int j;
	int t;
	int sum=0;
	int jud_a=0;
	int jud_b=0;
	int k=1;
	int *ans; 
	char str_a[20];
	char str_b[20];
	char str_ans[8];
	
	scanf("%d",&count);
	ans=malloc(sizeof(int) * count);
	for(i=0;i<count;i++){
		scanf("%s %s",&str_a,&str_b);
		strcat(str_a, "\0");
		strcat(str_b, "\0");
		
		
		
		for(j=0 ;str_a[j]!='\0';j++){
			
			switch(str_a[j]){
			case  'm':  sum=sum+k*1000;
				    k=1;
				    break;
			case  'c':  sum=sum+k*100;
				    k=1;
					break;
			case  'x':  sum=sum+k*10;
				    k=1;
					break;
			case  'i':  sum=sum+k*1;
				    k=1;
					break;
			case  '2':k=2; break;
			case  '3':k=3; break;
			case  '4':k=4; break;
			case  '5':k=5; break;
			case  '6':k=6; break;
		    case  '7':k=7; break;
			case  '8':k=8; break;
			case  '9':k=9; break;
			}
			
		}
		
		for(j=0 ;str_b[j]!='\0';j++){
			
			switch(str_b[j]){
			case  'm':  sum=sum+k*1000;
				    k=1;
				    break;
			case  'c':  sum=sum+k*100;
				    k=1;
					break;
			case  'x':  sum=sum+k*10;
				    k=1;
					break;
			case  'i':  sum=sum+k*1;
				    k=1;
					break;
			case  '2':k=2; break;
			case  '3':k=3; break;
			case  '4':k=4; break;
			case  '5':k=5; break;
			case  '6':k=6; break;
		    case  '7':k=7; break;
			case  '8':k=8; break;
			case  '9':k=9; break;
			}
			
			
		}
		ans[i]=sum;
		sum=0;
	}
	for(i=0;i<count;i++){
		
		
		j=0;
		jud_a=ans[i]/1000;
		jud_b=ans[i]%1000;
		
	
		
		if(jud_a!=0){
			
			switch(jud_a){
			case  1:j--; break;	
			case  2:str_ans[j]='2'; break;
			case  3:str_ans[j]='3'; break;
			case  4:str_ans[j]='4'; break;
			case  5:str_ans[j]='5'; break;
			case  6:str_ans[j]='6'; break;
			case  7:str_ans[j]='7'; break;
			case  8:str_ans[j]='8'; break;
			case  9:str_ans[j]='9'; break;
			}
		
			j++;
			str_ans[j]='m';
			j++;
		}
		
		jud_a=jud_b/100;
		jud_b=jud_b%100;
		
		
		
		if(jud_a!=0){
			
			switch(jud_a){
			case  1:j--; break;	
			case  2:str_ans[j]='2'; break;
			case  3:str_ans[j]='3'; break;
			case  4:str_ans[j]='4'; break;
			case  5:str_ans[j]='5'; break;
			case  6:str_ans[j]='6'; break;
			case  7:str_ans[j]='7'; break;
			case  8:str_ans[j]='8'; break;
			case  9:str_ans[j]='9'; break;
			}
		
			
			j++;
			str_ans[j]='c';
			j++;
		}
		
		jud_a=jud_b/10;
		jud_b=jud_b%10;
		
		
		
		if(jud_a!=0){
			
			switch(jud_a){
			case  1:j--; break;	
			case  2:str_ans[j]='2'; break;
			case  3:str_ans[j]='3'; break;
			case  4:str_ans[j]='4'; break;
			case  5:str_ans[j]='5'; break;
			case  6:str_ans[j]='6'; break;
			case  7:str_ans[j]='7'; break;
			case  8:str_ans[j]='8'; break;
			case  9:str_ans[j]='9'; break;
			}
	
			
			j++;
			str_ans[j]='x';
			j++;
		}
		
		jud_a=jud_b/1;
		
		
		
		if(jud_a!=0){
			
			switch(jud_a){
			case  1:j--; break;	
			case  2:str_ans[j]='2'; break;
			case  3:str_ans[j]='3'; break;
			case  4:str_ans[j]='4'; break;
			case  5:str_ans[j]='5'; break;
			case  6:str_ans[j]='6'; break;
			case  7:str_ans[j]='7'; break;
			case  8:str_ans[j]='8'; break;
			case  9:str_ans[j]='9'; break;
			}
			
			j++;
			str_ans[j]='i';
			j++;
		}
		
		
		str_ans[j]='\0';
		printf("%s\n",str_ans);
		
		for(t=0;t<8;t++){
			str_ans[t]='\0';
		}
			
		
	}
	free(ans);
   return 0;			
	
}
