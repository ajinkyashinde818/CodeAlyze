#include<bits/stdc++.h>
using namespace std;

int fatoi(char s[], int p){
  int temp = 0;
  int i;
  for(i = 0;s[i] != '\0';++i){
    if(s[i] != '.'){
      temp *= 10;
      temp += s[i] - '0';
    }
  }
  // temp /= pow(10.0, (strlen(s) - (p + 1)));
  return temp;
}

int atoi2(char s[]){
  int temp1 = 0;
  for(int i = 0;s[i] != ')';++i){
    if(s[i] != '(' && s[i] != '.'){
      temp1 *= 10;
      temp1 += s[i] - '0';
    }
  }
  int temp2 = 0;
  for(int i = 0;s[i] != '(';++i){
    if(s[i] != '.'){
      temp2 *= 10;
      temp2 += s[i] - '0';
    }
  }
  // cout << temp1 << "-" << temp2 << endl;
  return temp1 - temp2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char s[15];
  cin >> s;
  int piriod_p = 0;
  bool flag = false; // "("が含まれているならtrue
  for(int i = 0;s[i] != '\0' && !flag;++i){
    if(s[i] == '('){
      flag = true;
    }else if(s[i] == '.'){
      piriod_p = i;
    }
  }

  if(!flag){
    int temp;
    temp = fatoi(s, piriod_p);
    /*
      for(int i = 0;i < strlen(s) - (piriod_p + 1);++i){
      temp *= 10;
      }
    */
    double mot = pow(10, strlen(s) - (piriod_p + 1));
    int ans_mot = (int)mot;
    int g = __gcd(ans_mot, temp);
    cout << temp / g << '/' << ans_mot / g << endl;
  }else{
    int p1 = 0;
    int p2 = 0;
    for(int i = piriod_p;s[i] != ')';++i){
      if(s[i] >= '0' && s[i] <= '9'){
	++p1;
      }
    }
    for(int i = piriod_p;s[i] != '(';++i){
      if(s[i] >= '0' && s[i] <= '9'){
	++p2;
      }
    }
    /*
      cout << "p1 = " << p1 << endl;
      cout << "p2 = " << p2 << endl;
    */
    int mot = (int)pow(10, p1) - (int)pow(10, p2);
    int chi = atoi2(s);
    // 約分
    int g = __gcd(chi, mot);
    cout << chi / g << "/" << mot / g << endl;
  }
  return 0;
}
