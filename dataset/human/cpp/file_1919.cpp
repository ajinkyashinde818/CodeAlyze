#include<cmath>
#include<cstdio>
using namespace std;
typedef unsigned int ui;
int main(){
  int q;
  scanf("%d",&q);
  while(q--){
    ui bit;
    scanf("%x",&bit);
    if(bit >> 31 & 1) putchar('-');
    int Seisu = ( bit & 0x7FFFFFFF ) >> 7;
    int Syosu = ( bit & 0x0000007F );
    double ans = 0.0;
    int keta = 0;
    for(int j = 0 ; j < 7 ; j++){
      if(Syosu & (1 << (6-j))){
        ans += pow(0.5,j+1);
        keta = j;
      }
    }
    printf("%.*lf\n",keta+1,Seisu+ans);
  }
}
