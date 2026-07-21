#include<stdio.h>
#include<string.h>
	int main(){
		int n,A,B,x,y,xy,i;
		char a[20],b[20];
		scanf("%d",&n);
		while(n-->0){
			x=0;
			y=0;
			scanf("%s %s",a,b);
			A=strlen(a);
			for(i=0;i<A;i++)
				if(a[i]=='m'||a[i]=='c'||a[i]=='x'||a[i]=='i'){
					if(i!=0){
						if(a[i-1]!='m'&&a[i-1]!='c'&&a[i-1]!='x'&&a[i-1]!='i'){
							if(a[i]=='m')
								x+=(a[i-1]-'0')*1000;
							else if(a[i]=='c')
								x+=(a[i-1]-'0')*100;
							else if(a[i]=='x')
								x+=(a[i-1]-'0')*10;
							else
								x+=a[i-1]-'0';
						}
						else {
							if(a[i]=='m')
								x+=1000;
							else if(a[i]=='c')
								x+=100;
							else if(a[i]=='x')
								x+=10;
							else
								x+=1;
						}
					}
					else {
						if(a[i]=='m')
								x+=1000;
							else if(a[i]=='c')
								x+=100;
							else if(a[i]=='x')
								x+=10;
							else
								x+=1;
					}
			}
			B=strlen(b);
			for(i=0;i<B;i++)
				if(b[i]=='m'||b[i]=='c'||b[i]=='x'||b[i]=='i'){
					if(i!=0){
						if(b[i-1]!='m'&&b[i-1]!='c'&&b[i-1]!='x'&&b[i-1]!='i'){
							if(b[i]=='m')
								y+=(b[i-1]-'0')*1000;
							else if(b[i]=='c')
								y+=(b[i-1]-'0')*100;
							else if(b[i]=='x')
								y+=(b[i-1]-'0')*10;
							else
								y+=b[i-1]-'0';
						}
						else {
							if(b[i]=='m')
								y+=1000;
							else if(b[i]=='c')
								y+=100;
							else if(b[i]=='x')
								y+=10;
							else
								y+=1;
						}
					}
					else {
						if(b[i]=='m')
								y+=1000;
							else if(b[i]=='c')
								y+=100;
							else if(b[i]=='x')
								y+=10;
							else
								y+=1;
					}
			}
			xy=x+y;
			if(xy/1000>1)
				printf("%d",xy/1000);
			if(xy/1000!=0)
			printf("m");
			xy-=(xy/1000)*1000;
			
			
			if(xy/100>1)
				printf("%d",xy/100);
			if(xy/100!=0)
			printf("c");
			xy-=(xy/100)*100;
			
			if(xy/10>1)
				printf("%d",xy/10);
				if(xy/10!=0)
			printf("x");
			xy-=(xy/10)*10;
			
			if(xy>1)
				printf("%d",xy);
			if(xy!=0)
			printf("i");
			printf("\n");
		}
		return 0;
}
