#include <stdio.h>
#include <string.h>
char arr[500010], s[10010], ch;
int main(void) {
	int n, i, j, h, t, idx=0, num, temp, num1;
	scanf("%s", s);
	scanf("%d", &n);
	h=250000; 
	t=h+strlen(s)-1;
	for(i=h; i<=t; i++)
		arr[i]=s[idx++];
	for(i=0; i<n; i++){
		scanf("%d", &num);
		if(num==1){
			temp=h;
			h=t;
			t=temp;		
		}
		else{
			scanf("%d", &num1);
			scanf(" %c", &ch);
			if(num1==1){
				if(h>t){
					arr[h+1]=ch;
					h++;
				}
				else{
					arr[h-1]=ch;
					h--;
				}
			}
			else{
				if(h>t){
					arr[t-1]=ch;
					t--;
				}
				else{
					arr[t+1]=ch;
					t++;
				}
			}
		}
	}
	if(h<t){
		for(i=h; i<=t; i++)	
			printf("%c", arr[i]);	
	}
	else{
		for(i=h; i>=t; i--)
			printf("%c", arr[i]);
	}
	return 0;
}
