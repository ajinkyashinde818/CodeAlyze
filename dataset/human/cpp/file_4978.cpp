#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,r;
int main(){
	n=read(),r=read();
	if(n>=10){
		printf("%d\n",r);
	}
	else{
		printf("%d\n",r+100*(10-n));
	}
	return 0;
}
