#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2*1e5;

int n,x[N],y[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&y[i]);
	}
	sort(y,y+n,cmp);
	int flag=0;
	for(int i=0;i<n;i++){
		if(x[i]==y[i]){
			flag=i;
			break;
		}
	}
	while(x[flag]==y[flag]){
		for(int i=0;i<n;i++){
			if(x[i]!=x[flag] && y[i]!=x[flag]){
				swap(y[i],y[flag]);
				flag++;
				break;
			}
			if(i==n-1){
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes\n");
	for(int i=0;i<n;i++){
		printf("%d ",y[i]);
	}
	return 0;
}
