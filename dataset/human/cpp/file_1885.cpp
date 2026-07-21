#include<iostream>
#include<cstdio>
using namespace std;

void bit_16to2(char);

int bit_2[32],a;

int main(){

  char bit_16[8];
  long long b,n,ans_1,ans_2,c=5000000;
  bool check1,check2;

  cin >>n;
  
  for(int j=0 ; j < n ; j++){
 
    check1=false;
    check2=false;
    a=0;
    b=8388608;
    c=5000000;
    ans_1=0;
    ans_2=0;
  
    for(int i=0 ; i < 8 ; i++)cin >>bit_16[i];
    
    for(int i=0 ; i < 8 ; i++)bit_16to2(bit_16[i]);
    
    for(int i=1 ; i < 25 ; i++){
      if(bit_2[i]==1){
	ans_1+=b;
      }
      b/=2;
    }
    for(int i=25 ; i < 32 ; i++){
      if(bit_2[i]==1){
	ans_2+=c;
      }
      c/=2;
    }
    
    //cout <<ans_2<<endl;
    
    if(ans_2 != 0 && ans_2 < 1000000)check1=true;
    if(ans_2 != 0 && ans_2 < 100000)check2=true;
    
    
    while(1){
      if(ans_2 !=0 && ans_2 % 10 == 0){
	ans_2/=10;
      }else{
	break;
      }
    }

    
    if(bit_2[0] == 1)cout <<"-";
    
    cout <<ans_1<<".";
    if(check1)cout <<"0";
    if(check2)cout <<"0";
    cout <<ans_2;
    cout <<endl;
  }
  return 0;
  
}
void bit_16to2(char c){

  int bit,b=8;

  if(c >= 'a' && c <= 'f'){
    bit=c-'a'+10;
  }else{
    bit=c-'0';
  }
  
  for(int i=0 ; i < 4 ; i++){
    if(bit / b > 0){
      bit_2[a]=1;
      bit%=b;
    }else{
      bit_2[a]=0;
    }
    a++;
    b/=2;
  }

}
