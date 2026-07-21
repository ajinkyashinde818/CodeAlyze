#include<stdio.h>
#include<string.h>

int main(){
	char s[100050];
	char temp[10];
	scanf("%s",s);
	int i=0, end=strlen(s);
	int isPosible = 1;
	
	while(isPosible){
		
		if(i==end){
			break;
		}
		strncpy(temp,s+i,5);
		i+=5;
		if(strcmp(temp,"dream")!=0 && strcmp(temp,"erase")!=0){
			isPosible=0;
			//puts("No match");
		}else if(strcmp(temp,"erase")==0){//頭5文字が eraseの場合　次の文字が rならばそれも取り除く
			//puts("erase");
			if(s[i]=='r'){
				//puts("eraser");
				i++;
			}
		}else{//頭5文字が dreamの場合
			//puts("dream");
			if(s[i]=='e' && s[i+1] == 'r'){
				//puts("dreamer?");
				
				strncpy(temp,s+i,5);//dreamerase?
				if(strcmp(temp,"erase")!=0){
					i+=2;
					//puts("dreamer");
				}
			}
		}
	}
	
	if(isPosible){
		puts("YES");
	}else{
		puts("NO");
	}

	return 0;
}
