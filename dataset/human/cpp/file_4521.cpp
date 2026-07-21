#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int T,D,ta,tb,da,db;
  double mn;
  cin>>T>>D>>ta>>tb>>da>>db;
  mn=100;
  for(int i=0;i<=D;i+=da){
    for(int j=0;j<=D;j+=db){
      if(i+j>D)break;
      double C=1.0*(ta*i+tb*j)/(i+j);
      if(T-C>=0&&mn>T-C)mn=T-C;
      else if(C-T>0&&mn>C-T)mn=C-T;
    }
  }
  printf("%.10f\n",mn);
  return 0;
}
