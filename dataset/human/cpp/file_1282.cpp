/*
    �����悭�ǂ����I
    �_���I�ɍl���悤�I
    �T���v�����m�F���悤!
    ��΂ɒ��߂�ȁI
    �H�v������I
    �z��͏������߂ɂƂ��Ă���

    Twitter�͏I���܂Ń��O�A�E�g�I
    �i�ԈႦ�ĉ�@���c�C�[�g���Ă͂����Ȃ�����j

*/
//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<stdio.h>
#include<cstring>
//namespace
using namespace std;
//�J��Ԃ�
#define REP(i, m, n) for(int i=(int)m; i<(int)n; ++i)
#define rep(i, n) REP(i, 0, n)
//�C�e���[�^
#define all_range(C) begin(C), end(C)
//�ȗ���
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
typedef pair<string,int> pst;

const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
//�ő�ŏ�
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) {if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) {if(a<b) a=b;}

//�֐�

//�ő���񐔂����߂�
ll my_gcd(ll x, ll y) {
  ll r;

  while(y!=0) {
    r = x%y;
    x = y;
    y = r;
  }

  return x;
}

//�ŏ����񐔂����߂�
ll my_lcm(ll x, ll y) {

  return (x*y)/my_gcd(x,y);
}

//x��y������߂� ���Q�l�F10^18��܂�
ll my_pow(ll x, ll y) {
  ll sum = 1;

  while(y>0) {
    sum *= x;
    --y;
  }

  return sum;
}

/*�l���������X�y�[�X


*/

//main.cpp----------------------------


int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;

  int cnt = 0;
  for(int i=0; i<=n; ++i) {
    for(int j=0; j<=n; ++j) {
      int k = n-(i*r+j*g);
      if(k%b==0&&k>=0) ++cnt;
    }
  }

  cout << cnt << endl;

  return 0;
}
