#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef pair<int,int> p;
int tx,ty,sx,sy;
double r,rx,ry;
bool cir(double x,double y){
	return (x-rx)*(x-rx)+(y-ry)*(y-ry)<r*r;
}
int main()
{
    int n,m;
	while(cin>>n&&n){
		pair<int,p> wall[100];//<r,<x,y>>
		for(int i=0;i<n;i++)cin>>wall[i].second.first>>wall[i].second.second>>wall[i].first;
		cin>>m;
		for(int i=0;i<m;i++){
			string ans="Danger";
			cin>>tx>>ty>>sx>>sy;
			double a,b,c;
			if(tx!=sx&&ty!=sy){
				a=(double)(ty-sy)/(tx-sx);
				b=(double)-1;
				c=ty-(double)a*tx;
			}else if(tx==sx){
				a=1;
				b=0;
				c=-tx;
			}else if(ty==sy){
				a=0;
				b=1;
				c=-ty;
			}
			double bo=sqrt(a*a+b*b);
			double d=(a*a+b*b)/(a*b);
			for(int j=0;j<n;j++){
				r=(double)wall[j].first;
				rx=(double)wall[j].second.first;
				ry=(double)wall[j].second.second;
				double shi=abs(a*rx+b*ry+c);
				double res=shi/bo;
				//printf("a:%.3f b:%.3f c:%.3f shi:%.3f bo:%.3f res:%.3f\n",a,b,c,shi,bo,res);
				if(r<res)continue;
				double px,py;//?????????????????????????????¨?????????
				if((a!=0)&&(b!=0)){
					px=(b/a*rx-ry-c/b)/d;
					py=-a/b*px-c/b;
				}else if(a!=0){//y????????????
					px=-c;
					py=ry;
				}else if(b!=0){//x????????????
					py=-c;
					px=rx;
				}
				if(cir((double)sx,(double)sy)&&cir((double)tx,(double)ty)){
					continue;
				}else if(cir((double)sx,(double)sy)!=cir((double)tx,(double)ty)||
					((double)min(sx,tx)<px&&px<(double)max(sx,tx))||((double)min(sy,ty)<py&&py<(double)max(sy,ty))){
					ans="Safe";
					break;
				}
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}
