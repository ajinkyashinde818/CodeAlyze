#include<iostream>
#include<bits/stdc++.h>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <map>
typedef long long ll;
using namespace std;
typedef pair<string,int> PAIR;


int main()
{
	
	int n,m;
	cin>>n>>m;
	if(n>=10) cout<<m<<endl;
	else{
		int t = 100*(10-n);
		cout<<m+t<<endl;
		
	}
	
	return 0;
 }
