#include <cstring>
#include <bits/stdc++.h>
using namespace std;
int main(){
long long counter1,counter2;
counter1=0;
counter2=0;
long long counter3=0;
long long N;
cin>>N;
long long a[N];
vector<long long>b(N);
for (int i=0;i<N;i++){
cin>>a[i];
b.at(i)=abs(a[i]);
counter1+=abs(a[i]);
if(a[i]<0)
counter2++;}
if (counter2%2==0)
cout<<counter1<<endl;
else{
sort(b.begin(),b.end());
for (int i=1;i<N;i++){
counter3+=b[i];}
cout<<counter3-b.at(0)<<endl;}}
