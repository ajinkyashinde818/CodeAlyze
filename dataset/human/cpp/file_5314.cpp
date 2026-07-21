/*
ID: wangjun30
LANG: C++11
TASK:
*/
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<list>
#include<unordered_set>
#include<vector>
#include<bitset>
#include<queue>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
//#include<fstream>
using namespace std;
//ifstream cin(".in");
//ofstream cout(".out");
int main(){
	int a,b;
	cin>>a>>b;
	cout<<b+max(0,10-a)*100;
	return 0;
}
