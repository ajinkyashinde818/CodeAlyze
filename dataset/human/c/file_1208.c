#include <stdio.h>
#include <string.h>
int main(){

int a[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int b[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char s[101];
char t[101];
scanf("%s%s",s,t);
int i = 0;
while(s[i] != '\0'){
	a[s[i] - 'a']++;
	i++;
}
i = 0;
while(t[i] != '\0'){
	b[t[i] - 'a']++;
	i++;
}
int si = 0;
int ti = strlen(t) - 1;
for(i = 0; i < 26; i++){
	while(a[i] != 0){
		s[si] = 97 + i;
		si++;
		a[i]--; 
	}
	while(b[i] != 0){
		t[ti] = 97 + i;
		ti--;
		b[i]--;
	}
}

if(strcmp(s,t) < 0){
	printf("Yes\n");
}else{
	printf("No\n");
}

return 0;
}
