#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
void f(double& v,double& w,double& x,double& y,int& n,int bx,int by,int ex,int ey,int cx,int cy,int cr){
  double vx,vy,px,py,ds;
  ds=sqrt((ex-bx)*(ex-bx)+(ey-by)*(ey-by));
  vx=(ex-bx)/ds;
  vy=(ey-by)/ds;
  ds=((ey-by)*cx+(bx-ex)*cy+(by-ey)*bx+(ex-bx)*by)/((ey-by)*vy-(bx-ex)*vx);
  px=cx-vy*ds;
  py=cy+vx*ds;
  if(0){
  }else if(cr>ds){
    n=2;
    ds=sqrt(cr*cr-ds*ds);
    v=px+vx*ds;
    w=py+vy*ds;
    x=px-vx*ds;
    y=py-vy*ds;
  }else if(cr<ds){
    n=0;
  }else{
    n=1;
    v=px;
    w=py;
  }
  return;
}
int g(int bx,int by,int ex,int ey,int cx,int cy,int cr){
  int n;
  double v,w,x,y;
  f(v,w,x,y,n,bx,by,ex,ey,cx,cy,cr);
  if(0){
  }else if(n==0){
    return 0;
  }else if(n==1){
    if(bx==ex)
      return min(by,ey)<=w&&w<=max(by,ey);
    else
      return min(bx,ex)<=v&&v<=max(bx,ex);
  }else{
    if(bx==ex)
      return min(by,ey)<=min(w,y)&&max(w,y)<=max(by,ey);
    else
      return min(bx,ex)<=min(v,x)&&min(v,x)<=max(bx,ex);
  }
}
int main(){
  int i,j;
  int cb[100],ce[100],cx[100],cy[100],cr[100],bx,by,ex,ey,m,n;
  int *a;
  while(cin>>n&&n){
    for(i=0;i<n;i++)
      cin>>cx[i]>>cy[i]>>cr[i];
    cin>>m;
    a=new int[m];
    for(i=0;i<m;i++){
      cin>>bx>>by>>ex>>ey;
      for(j=0;j<n;j++){
	cb[j]=(cx[j]-bx)*(cx[j]-bx)+(cy[j]-by)*(cy[j]-by)>cr[j]*cr[j];
	ce[j]=(cx[j]-ex)*(cx[j]-ex)+(cy[j]-ey)*(cy[j]-ey)>cr[j]*cr[j];
	if(cb[j]^ce[j])
	  break;
	if(cb[j]&&ce[j]&&g(bx,by,ex,ey,cx[j],cy[j],cr[j]))
	  break;
      }
      if(j==n)
	a[i]=1;
      else
	a[i]=0;
    }
    for(i=0;i<m;i++)
      cout<<(a[i]?"Danger":"Safe")<<endl;
  }
  return 0;
}
