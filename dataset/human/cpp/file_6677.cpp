#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
 int i,j,n,m,f;
 int a,b,c,d,r,x1,x2,y1,y2,mx[101],my[101],mr[101];
 vector<int> tx,ty,sx,sy;
 while(cin >> n) {
	 if (n==0) break;
	 for (i=0;i<n;i++)  cin >> mx[i] >> my[i] >> mr[i];
	 cin >> m;
	 for (i=0;i<m;i++) { cin >> a >> b >> c >> r; tx.push_back(a); ty.push_back(b); sx.push_back(c); sy.push_back(r);}
	 for (i=0;i<m;i++) { 
		 for (j=0,f=0;j<n;j++) {
		  x1=tx[i]-mx[j]; y1=ty[i]-my[j]; x2=sx[i]-mx[j]; y2=sy[i]-my[j]; r=mr[j];
		  a=x1*x1+y1*y1; b=x2*x2+y2*y2;
		  if ( a<r*r && b<r*r) continue;
		  if ((a<r*r && b>r*r) || (a>r*r && b<r*r)) f=1;
		  a=x2-x1; b=y2-y1;
		  c=b*b*(r*r-x1*x1)+a*a*(r*r-y1*y1)+2*a*b*y1*x1;
		  d=(a*(-x1)+b*(-y1))*((-a)*(-x2)+(-b)*(-y2));
		  if (c>=0 && d>=0) f=1; 
		 }
		 if (f==1) cout << "Safe" << endl; else cout << "Danger" << endl;
	 }
	 tx.clear(); ty.clear(); sx.clear(); sy.clear();
 }
 return 0;
}
