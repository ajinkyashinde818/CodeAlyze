#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(void){
	int n,m,a;
	cin>>n>>m;
	std::list<int> e;
	bool f[200001];
	list<int>::iterator exist[200001];
	for(int i=1;i<=n;i++) f[i]=true;
	while(m--){
		cin>>a;
		if(f[a])e.push_back(a);
		else{
			e.erase(exist[a]);
			e.push_back(a);
		}
		f[a]=false;
		exist[a]=e.end();
		exist[a]--;
	}
	for(list<int>::reverse_iterator it=e.rbegin();it!=e.rend();it++){
		cout<<*it<<endl;
	}
	for(int i=1;i<=n;i++){
		if(f[i])cout<<i<<endl;
	}
}
