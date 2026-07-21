#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll n,tmp,num,m_num=0,abs_min=10000000000,abs_sum=0;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> tmp;
    num = abs(tmp);
    abs_sum+=num;
    if(tmp<0){
      m_num++;
    }
    if(num<abs_min){
      abs_min=num;
    }
  }
  if(m_num%2==0){
    cout << abs_sum<<endl;
  }else{
    cout << abs_sum-2*abs_min<<endl;
  }
    
}
