#include <iostream>
#include <string>

using namespace std;

int main(){
  string map1[50];
  string map2[50];
  int M,N;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> map1[i];
  }
  for(int i=0;i<M;i++){
    cin >> map2[i];
  }
  for(int i=0;i<=N-M;i++)
  {
    for(int j=0;j<=N-M;j++)
    {
      for(int k=0;k<M;k++)
      {
        for(int l=0;l<M;l++)
        {
          if(map1[i+l][j+k]!=map2[l][k])
          {
            goto A;
          }
        }
      }
      goto end;
A:;
    }
  }
  cout << "No"<<endl;
  return 0;
end:
  cout << "Yes" <<endl;
  return 0;
}
