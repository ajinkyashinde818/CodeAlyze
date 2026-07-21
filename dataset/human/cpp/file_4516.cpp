#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  double t,d;
  double t_a,t_b,d_a,d_b;
  cin>>t>>d>>t_a>>t_b>>d_a>>d_b;
  double min=100000;
  for(int i=0;i<=d;i+=d_a){
    for(int j=0;j<=d;j+=d_b){
      if(i+j==0 || i+j>d)continue;
      double nt=(t_a*i+t_b*j)/(i+j);
      if(abs(t-min)>abs(t-nt)){
	min=nt;
      }
    }
  }
  printf("%.10lf\n",abs(t-min));
  return 0;
}
