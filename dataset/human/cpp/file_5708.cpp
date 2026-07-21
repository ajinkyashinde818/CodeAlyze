#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	using LL = long long; 
	struct node
	{
		LL d;
		int l, r;
		node(LL d):d(d) { l = r = -1; }
	};

	int N;
	LL L;
	cin >> N >> L;
	vector<node>v;
	v.push_back(node(0));
	for( int n = 0; n < N; n++ )
	{
		int now = 0;
		string s;
		cin >> s;

		for( int i = 0; i < s.length(); i++ )
		{
			if( s[i] == '0' )
			{
				if( v[now].l != -1 )
				{
					now = v[now].l;
				}
				else
				{
					v[now].l = v.size();
					v.push_back(node(v[now].d + 1));
					now = v[now].l;
				}
			}
			else
			{
				if( v[now].r != -1 )
				{
					now = v[now].r;
				}
				else
				{
					v[now].r = v.size();
					v.push_back(node(v[now].d + 1));
					now = v[now].r;
				}
			}
		}
	}

	LL ans = 0;
	for( auto i : v )
	{
		if( i.l == -1 && i.r == -1 ) 
			continue;

		if( i.l == -1 || i.r == -1 ) 
			ans ^= (L - i.d)&(i.d - L);
	}

	if( ans ) 
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
}
