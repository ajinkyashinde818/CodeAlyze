#include<stdio.h>
int search(char a[]){
	int i,score,box=0;
	for(i=0;;i++){
		if(a[i]=='\0')break;
		switch(a[i]){
			case 'm' :if(a[i-1]>='2'&&a[i-1]<='9'&&i!=0)box+=(a[i-1]-'0')*1000;else box+=1000;break;
			case 'c' :if(a[i-1]>='2'&&a[i-1]<='9'&&i!=0)box+=(a[i-1]-'0')*100;else box+=100;break;
			case 'x' :if(a[i-1]>='2'&&a[i-1]<='9'&&i!=0)box+=(a[i-1]-'0')*10;else box+=10;;break;
			case 'i' :if(a[i-1]>='2'&&a[i-1]<='9'&&i!=0)box+=(a[i-1]-'0')*1;else box+=1;;break;
		}
	}
	return box;
}
int main(void){
	int n,i,j,flag,box;
	char mcxi1[10],mcxi2[10],ans[10];
	scanf("%d",&n);
	while(n--){
		for(i=0;i<10;i++){mcxi1[j]='\0';mcxi2[j]='\0';ans[i]='\0';}
		flag=0;
		scanf("%s%s",mcxi1,mcxi2);
		box=search(mcxi1);
		box+=search(mcxi2);
		for(i=0;i<10;i++){
			if(ans[i]=='\0'){
				if(box/1000>1&&flag<1){ans[i]='0'+box/1000;ans[i+1]='m';box-=1000*(box/1000);flag=1;}
				else if(box/1000>0&&flag<1){ans[i]='m';box-=1000;flag=1;}
				else if(box/100>1&&flag<2){ans[i]='0'+box/100;ans[i+1]='c';box-=100*(box/100);flag=2;}
				else if(box/100>0&&flag<2){ans[i]='c';box-=100;flag=2;}
				else if(box/10>1&&flag<3){ans[i]='0'+box/10;ans[i+1]='x';box-=10*(box/10);flag=3;}
				else if(box/10>0&&flag<3){ans[i]='x';box-=10;flag=3;}
				else if(box>1&&flag<4){ans[i]='0'+box;ans[i+1]='i';flag=4;}
				else if(box>0&&flag<4){ans[i]='i';flag=4;}
			}
			if(flag==4)break;
		}
		printf("%s\n",ans);
	}
	return 0;
}
