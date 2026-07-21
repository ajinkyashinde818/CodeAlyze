#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
using ll=long long;

int main(void){
  int N;
  string  S;
   cin >> N >> S;
  vector<int> number(26);
  for(int i=0;i<26;i++) {
    number.at(i)++;
  }
  
  for(int i=0;i<N;i++){
    if(S.at(i)=='a') number.at(0)++;
    if(S.at(i)=='b') number.at(1)++;  
    if(S.at(i)=='c') number.at(2)++;
    if(S.at(i)=='d') number.at(3)++;
    if(S.at(i)=='e') number.at(4)++;  
    if(S.at(i)=='f') number.at(5)++;
    if(S.at(i)=='g') number.at(6)++;
    if(S.at(i)=='h') number.at(7)++;  
    if(S.at(i)=='i') number.at(8)++;
    if(S.at(i)=='j') number.at(9)++;
    if(S.at(i)=='k') number.at(10)++;  
    if(S.at(i)=='l') number.at(11)++;
    if(S.at(i)=='m') number.at(12)++;
    if(S.at(i)=='n') number.at(13)++;  
    if(S.at(i)=='o') number.at(14)++;
    if(S.at(i)=='p') number.at(15)++;
    if(S.at(i)=='q') number.at(16)++;  
    if(S.at(i)=='r') number.at(17)++;
    if(S.at(i)=='s') number.at(18)++;
    if(S.at(i)=='t') number.at(19)++;  
    if(S.at(i)=='u') number.at(20)++;
    if(S.at(i)=='v') number.at(21)++;
    if(S.at(i)=='w') number.at(22)++;  
    if(S.at(i)=='x') number.at(23)++;
    if(S.at(i)=='y') number.at(24)++;
    if(S.at(i)=='z') number.at(25)++;
  }
  ll ans=1LL;
   for(int i=0;i<26;i++) {
     ans=(ans*number.at(i))%1000000007;
   }
  cout << ans-1 << endl; 
}
