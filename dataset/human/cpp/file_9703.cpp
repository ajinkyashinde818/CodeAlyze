#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  string S;
  string diffS = "";
  vector<int> apperNumOfEachChar;
  cin>>N>>S;
  long long ans;
  
  //shori
  for(int i = 0; i<N; i++){
    auto apperChar = find(diffS.begin(),diffS.end(),S[i]);
    if(apperChar == diffS.end()){//*itrがまだ出てない文字のとき
      diffS.push_back(S[i]);
      apperNumOfEachChar.push_back(1);
    }
    else {//*itrが既に出ている文字のとき
      int indx = apperChar-diffS.begin();
      apperNumOfEachChar[indx] += 1;
    }
  }
  ans = 1;
  for(int i = 0; i<diffS.size(); i++){
    ans *= apperNumOfEachChar[i]+1;
    ans = ans%1000000007;
    //cout<<apperNumOfEachChar[i]<<" ";
  }
  ans -= 1;
  //cout<<endl;
  //cout<<diffS<<endl;
  cout<<ans<<endl;
  return 0;
}
