#include<iostream>
using namespace std;
int main()
{
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int rlim = N/R;
    int glim;
    int cnt = 0;
    for(int r = 0;r<=rlim;r++){
      int tmpN = N;
      tmpN = tmpN - R*r;
      //cout<<tmpN;
      if(tmpN == 0){
        cnt++;
      }
      else{
        glim = tmpN/G;
        for(int g = 0;g<=tmpN/G;g++){
          int prev = tmpN;
          tmpN = tmpN - G*g;
          if(tmpN % B == 0){
            cnt++;

          }
          tmpN = prev;
        }
      }
    }
    cout<<cnt<<endl;
    return 0;
}
