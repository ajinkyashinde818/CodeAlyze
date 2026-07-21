#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
using namespace std;

long long mypower(long long x, int y){
  long long result = 1;
  while(y > 0){
    result *= x;
    y--;
  }
  return result;
}


int main(){
  long long N;
  cin >> N;

  string S;
  cin >> S;

  long long alphabet[26] = {};
  for(int i=0;i<26;i++){
    alphabet[i] = 0;
  }

  for(int i=0;i<N;i++){
    if(S[i] == 'a'){
      alphabet[0]++;
    }else if(S[i] == 'b'){
      alphabet[1]++;
    }else if(S[i] == 'c'){
      alphabet[2]++;
    }else if(S[i] == 'd'){
      alphabet[3]++;
    }else if(S[i] == 'e'){
      alphabet[4]++;
    }else if(S[i] == 'f'){
      alphabet[5]++;
    }else if(S[i] == 'g'){
      alphabet[6]++;
    }else if(S[i] == 'h'){
      alphabet[7]++;
    }else if(S[i] == 'i'){
      alphabet[8]++;
    }else if(S[i] == 'j'){
      alphabet[9]++;
    }else if(S[i] == 'k'){
      alphabet[10]++;
    }else if(S[i] == 'l'){
      alphabet[11]++;
    }else if(S[i] == 'm'){
      alphabet[12]++;
    }else if(S[i] == 'n'){
      alphabet[13]++;
    }else if(S[i] == 'o'){
      alphabet[14]++;
    }else if(S[i] == 'p'){
      alphabet[15]++;
    }else if(S[i] == 'q'){
      alphabet[16]++;
    }else if(S[i] == 'r'){
      alphabet[17]++;
    }else if(S[i] == 's'){
      alphabet[18]++;
    }else if(S[i] == 't'){
      alphabet[19]++;
    }else if(S[i] == 'u'){
      alphabet[20]++;
    }else if(S[i] == 'v'){
      alphabet[21]++;
    }else if(S[i] == 'w'){
      alphabet[22]++;
    }else if(S[i] == 'x'){
      alphabet[23]++;
    }else if(S[i] == 'y'){
      alphabet[24]++;
    }else if(S[i] == 'z'){
      alphabet[25]++;
    }
  }

  long long result = 1;
  for(int i=0;i<26;i++){
    if(alphabet[i] != 0){
      result *= (alphabet[i] + 1);
      result = result % (mypower(10,9) + 7);
    }
  }
  result--;
  cout << result << "\n";
  return 0;
}
