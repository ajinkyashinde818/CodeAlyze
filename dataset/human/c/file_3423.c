#include<stdio.h>
#include<string.h>

int main(){
	
	
	int i,k=0,count;
	char S[100010],invS[100010],s1[]="maerd",s2[]="remaerd",s3[]="esare",s4[]="resare";
	scanf("%s",S);
	
	for(i=0;i<strlen(S);i++){
		invS[i]=S[strlen(S)-i-1];
	}
	
	
	while(k<=strlen(S)-1){
		count=0;
		for(i=0;i<strlen(s1);i++){
			if(invS[i+k]!=s1[i]){
				break;
			}
			if(i==strlen(s1)-1){
			k+=strlen(s1);
			count++;
			}
		}
		for(i=0;i<strlen(s2);i++){
			if(invS[i+k]!=s2[i]){
				break;
			}
			if(i==strlen(s2)-1){
			k+=strlen(s2);
			count++;
			}
		}
		for(i=0;i<strlen(s3);i++){
			if(invS[i+k]!=s3[i]){
				break;
			}
			if(i==strlen(s3)-1){
			k+=strlen(s3);
			count++;
			}
		}
		for(i=0;i<strlen(s4);i++){
			if(invS[i+k]!=s4[i]){
				break;
			}
			if(i==strlen(s4)-1){
			k+=strlen(s4);
			count++;
			}
		}
		if(count==0){
			printf("\n\nNO\n\n");
			return 0;
		}
		
		}
	
	printf("\n\nYES\n\n");
	
	return 0;
}
