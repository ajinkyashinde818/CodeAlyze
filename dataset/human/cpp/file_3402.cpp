#include<bits/stdc++.h>
using namespace std;

/*任意の2か所の符号を変えることは可能、例えばデータ格納配列A[N]が存在するとする。
A[i]とA[j]の二つの符号を変えたいとき、A[i]とA[i+1]、A[i+1]とA[i+2]、...、A[j-1]とA[j]と
選択していくと、A[i]とA[j]の間の値はいずれも(-1)を二回かけられているため元の値に戻る
よって負の値を正の値に変えていけばよいが、負の値が奇数個であった場合、一か所だけ
正の値に戻すことができない。(正の値に戻すにはペアを作らなければならないから)
よって絶対値の最小値を残すようにする。例外として、0がある場合は任意の負の値と0を
ペアとすることで処理可能*/

int abs(int a){
  if(a < 0)
    return -a;
  else
    return a;
}

int main(){       
  int N;
  cin >> N;
  
  int nmax = 1e9;                           //値の絶対値の最小値
  int minus_c = 0;                           //負の値の数
  int64_t sum = 0;                         //入力した値の絶対値の和
  bool exist_0 = false;                //入力値に0が含まれているか否か
  vector<int> A(N);                    //入力値の格納先

  for(int i = 0; i < N; i++){
    int val;
    cin >> val;
    A[i] = val;
    
    if(abs(val) < nmax)                  //絶対値が最小の入力値を格納
      nmax = abs(val);
    
    if(val < 0)                                      //負の値の数を格納
      minus_c++;
    else if(val == 0)                        //0の存在を確認
      exist_0 = true;

    sum += abs(val);
  }

  if(exist_0)
    cout << sum << endl;
  else if(minus_c & 1)
    cout << sum - 2 * nmax << endl;
  else
    cout << sum << endl;

  return 0;
  
}
