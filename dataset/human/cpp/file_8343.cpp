#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

bool is_match(vector<string> &ns, vector<string> &ms, int i_, int j_, int m){
  for(int i = 0;i<m;++i){
    for(int j = 0;j<m;++j){
      if(ns[i+i_][j+j_] != ms[i][j]){
	return false;
      }
    }
  }
  return true;
}

string matching(vector<string> &ns, vector<string> &ms, int n, int m){
  for(int i = 0;i < n-m+1;++i){
    for(int j = 0;j < n-m+1;++j){
      if(!is_match(ns, ms, i, j, m)){
	continue;
      }
      else return "Yes";
    }
  }
  return "No";
}

int main(void)
{
  int n,m;
  vector<string> ns, ms;
  cin >> n >> m;
  for(int i = 0;i < n;++i){
    string buf;
    cin >> buf;
    ns.push_back(buf);
  }
  for(int i = 0;i < m;++i){
    string buf;
    cin >> buf;
    ms.push_back(buf);
  }
  cout << matching(ns, ms, n, m) << endl;
  /*
    for(int i = 0;i < n;++i){
    cout << ns[i] << endl;
    }
    for(int i = 0;i < m;++i){
    cout << ms[i] << endl;
    }
  */
  return 0;
}
