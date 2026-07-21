#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

void MakeConvertData(map<char, string>*);
string ConvertHexToBinary(map<char, string>&, const string&);
void Calculate(const string&);

int main(){
  int i, n;
  string str, str_;
  map<char, string> data;

  MakeConvertData(&data);

  cin >> n;
  for(i=0; i<n; ++i){
    cin >> str_;
    str = ConvertHexToBinary(data, str_);
    Calculate(str);
  }
  return 0;
}

void MakeConvertData(map<char, string>* data){
  data->insert(make_pair('0', "0000"));
  data->insert(make_pair('1', "0001"));
  data->insert(make_pair('2', "0010"));
  data->insert(make_pair('3', "0011"));
  data->insert(make_pair('4', "0100"));
  data->insert(make_pair('5', "0101"));
  data->insert(make_pair('6', "0110"));
  data->insert(make_pair('7', "0111"));
  data->insert(make_pair('8', "1000"));
  data->insert(make_pair('9', "1001"));
  data->insert(make_pair('a', "1010"));
  data->insert(make_pair('b', "1011"));
  data->insert(make_pair('c', "1100"));
  data->insert(make_pair('d', "1101"));
  data->insert(make_pair('e', "1110"));
  data->insert(make_pair('f', "1111"));
}

string ConvertHexToBinary(map<char, string>& data, const string& str_){
  string str;
  for(int i=0; i<str_.size(); ++i){
    str.append(data[str_[i]]);
  }
  return str;
}

void Calculate(const string& str){
  int i, j, k;
  double ans = 0;

  for(i=24, j=0; i>0; --i, ++j){
    if(str[i] == '1') ans += pow(2.0, j);
  }
  for(i=25, j=-1, k=1; i<32; ++i, --j){
    if(str[i] == '1'){
      ans += pow(2.0, j);
      k = -j;
    }
  }

  if(str[0] == '1') cout << "-";
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(k);
  cout << ans << endl;
}
