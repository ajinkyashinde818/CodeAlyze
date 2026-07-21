#include <iostream>
using namespace std;

int main(void) {
	int i,j,k,cn[105][4],m[32],d[33],t,n,x,y;
	double s,g;
	char a[]="0123456889abcdef",b[9];
	for (i=0,t=48; i<16; i++) {	if (i==10) t=87;
	for (j=0;j<4;j++) if ((i & (1 << j))>0) cn[i+t][j]=1; else cn[i+t][j]=0;}
    for (i=7,x=1;i<32;i++,x*=2) d[i]=x;
	for (i=6,s=0.5;i>-1;i--,s/=2) d[i]=(int)(s*10000000); 
	cin >> n;
	for (k=0;k<n;k++) {
		cin >> b; t=31;
		for (j=0;j<8;j++) for(i=0;i<4;i++) m[t--]=cn[(int)b[j]][3-i]; 
		if (m[31]==1) cout << "-";
		for (i=7,x=0;i<31;i++) if (m[i]==1) x+=d[i];
		for (i=0,y=0;i<7;i++) if (m[i]==1) y+=d[i];
		if (y==0) cout << x  << ".0" << endl; else {
		 cout << x << "."; 
		 for (i=1000000;i>0;i/=10) if (i>y) cout << "0";
		 while( y>10 && (y % 10)==0) y=y/10;
		 cout << y << endl;
		}
		}
	return 0;
	}
