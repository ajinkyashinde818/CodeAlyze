#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;
//char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char a[50][50];
	char b[50][50];int n,m;
	int go(int i,int j){int p1=0;int p2=0;
		for(int k=i;k<m+i;k++){
		for(int s=j;s<m+j;s++){
			if(a[k][s]==b[p1][p2]){if(p1==m-1&&p2==m-1){return 1;}else p2++;}
			else return 0;
		}p2=0;p1++;}
	}//go
int main(){
int ct=0;int p2=0;
					cin>>n>>m;memset(a,'\0',sizeof(a));memset(b,'\0',sizeof(b));
					for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){cin>>a[i][j];}}
					for(int i=0;i<m;i++){
					for(int j=0;j<m;j++){cin>>b[i][j];}}
					for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
							if(go(i,j)){cout<<"Yes"<<endl;ct++;p2++;break;}
					}if(p2==1)break;}
				if(ct==0)cout<<"No"<<endl;
					
					

}
