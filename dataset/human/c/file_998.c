#include<stdio.h>
#include<string.h>
#define rep(i,j) for(int i=0;i<(j);i++)
int main(){
	int n,k[1000],l;
	char s[101];
	for(;;){
	    scanf("%d",&n);
	    if(!n)break;
	    rep(i,n){
	        scanf("%d",k+i);
	        k[i] = 52 - k[i];
	    }
	    scanf("%s",s);
        l = strlen(s);
        rep(i,l){
            s[i] = s[i]>='a' ? s[i]-'a':s[i]-'A'-26;
            s[i] = (s[i]+k[i%n]+52)%52;
            s[i] = s[i]>25?s[i]+'A'-26:s[i]+'a';
        }
        puts(s);
	}

	return 0;
}
