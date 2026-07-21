#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> a(n),b(n);
	map<int,int> ma,mb;
	for(int i=0;i<n;i++){
		cin >> a[i];
		ma[a[i]]++;
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
		mb[b[i]]++;
	}
	vector<pair<int,int>> v;
	for(auto &p:mb){
		if(ma.count(p.first)){
			if(p.second+ma[p.first]>n){
				cout << "No" << endl;
				return 0; 
			}
			v.push_back({min(p.second,ma[p.first]),p.first});
			p.second-=v.back().first;
		}
	}
	sort(v.rbegin(), v.rend());
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i].first;
	}
	map<int,vector<int>> mv;
	if(v.size()&&v[0].first*2>sum){
		// cout << "No" << endl;
		// return 0;
		int cnt=0;
		for(auto p:mb){
			if(p.first==v[0].second)continue;
			cnt+=p.second;
		}
		if(2*v[0].first-sum>cnt){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
			int noko=2*v[0].first-sum;
			vector<int> free;
			for(auto &p:mb){
				if(p.first==v[0].second)continue;
				if(p.second)mv[v[0].second].push_back(p.first);
				p.second--;
				noko--;
				free.push_back(v[0].second);
				if(noko==0)break;
			}
			vector<int> vv;
			for(int i=0;i<v.size();i++){
				if(i==0){
					for(int j=0;j<sum-v[0].first;j++){
						vv.push_back(v[i].second);
					}
				}
				else{
					for(int j=0;j<v[i].first;j++){
						vv.push_back(v[i].second);
					}
				}
			}
			int uo=sum-v[0].first;
			for(int j=0;j<vv.size();j++){
				mv[vv[j]].push_back(vv[(j+uo)%vv.size()]);
			}
			for(auto p:mb){
				for(int j=0;j<p.second;j++){
					free.push_back(p.first);
				}
			}
			for(int i=0;i<n;i++){
				if(mv[a[i]].size()){
					cout << mv[a[i]].back() << " ";
					mv[a[i]].pop_back();
				}
				else{
					cout << free.back() << " ";
					free.pop_back();
				}
			}
			cout << endl;
		}
		return 0;
	}
	cout << "Yes" << endl;
	vector<int> free;
	vector<int> vv;
	if(v.size()){
		for(int i=0;i<v.size();i++){
			if(0){
				for(int j=0;j<sum-v[0].first;j++){
					vv.push_back(v[i].second);
				}
			}
			else{
				for(int j=0;j<v[i].first;j++){
					vv.push_back(v[i].second);
				}
			}
		}
		int uo=v[0].first;
		for(int j=0;j<vv.size();j++){
			mv[vv[j]].push_back(vv[(j+uo)%vv.size()]);
		}
	}
	for(auto p:mb){
		for(int j=0;j<p.second;j++){
			free.push_back(p.first);
		}
	}
	for(int i=0;i<n;i++){
		if(mv[a[i]].size()){
			cout << mv[a[i]].back() << " ";
			mv[a[i]].pop_back();
		}
		else{
			cout << free.back() << " ";
			free.pop_back();
		}
	}
	cout << endl;
}
