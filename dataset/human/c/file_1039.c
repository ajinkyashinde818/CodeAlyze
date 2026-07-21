#include <stdio.h>
#define MAX 100

int main(){ 

	int i;
    int n = 0;
	char str[MAX];
  
   	scanf("%s", str);

    // printf("%s", str);

    for(i=0; i<(MAX-7); i++){
        if(str[i-7]=='F' && str[i-6]=='E' && str[i-5]=='S'&& str[i-4]=='T' 
        && str[i-3]=='I' && str[i-2]=='V' && str[i-1]=='A' && str[i]=='L') {
            n = i - 7;
        }
    }




    for(i=0; i<n; i++){
        printf("%c", str[i]);
    }



return 0;

}
