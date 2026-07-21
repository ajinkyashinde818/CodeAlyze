//default library
#include <stdio.h>
#include <string.h>
//extra library


//default define
#define ll long long int
#define fl(i,a,n) for(int i = a; i < (n); i++)
#define fls(i,a,s) for(int i = a; s[i] != '\0'; i++)
#define endl puts("")
#define kill return 0

//extra define


//declare function


//main code
int main() {
	int t,check = 0;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		if(a == b){
			check++;
		}else{
			check = 0;
		}
		if(check == 3){
			puts("Yes");
			kill;
		}
	}
	puts("No");
    return 0;
}

//functions
