#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main(){
    double t,d,t1,t2,d1,d2,m=999;
    cin>>t>>d>>t1>>t2>>d1>>d2;
    for(int i=0;i<=d;i+=d1)
        for(int j=0;i+j<=d;j+=d2)
            if(abs((t1*i+t2*j)/(i+j)-t)<m&&(i>0||j>0))
                m=abs((t1*i+t2*j)/(i+j)-t);
    printf("%.6f\n",m);
    
}
