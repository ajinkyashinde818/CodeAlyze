#include<bits/stdc++.h>
using namespace std;
map<int,int> f;
map<int,bool> us;
map<int,int> ds;
map<int,bool> us2;


int find(int val){
	if(ds[val]!=val+1)
	return ds[val]=find(ds[val]-1);
	else
	return val+1;
}

void add(int uno,int due){
	ds[find(uno)-1]=ds[find(due)-1];
}



int main(){
int n;
cin>>n;
int v[n],v1[n];
int temp=0;
for(int i=0;i<n;i++){
	cin>>v[i];
	temp^=v[i];
	
	f[v[i]]++;
}
//cout<<temp<<endl;
f[temp]++;
int cont=0;
bool ok=true;
int temp2=0;
for(int i=0;i<n;i++){
	cin>>v1[i];
	temp2^=v1[i];
	us[v1[i]]=true;
	f[v1[i]]--;
	if(f[v1[i]]<0){
		cont++;
	}
	if(cont>1){
		ok=false;
		break;
	}
}
f[temp2]--;
	if(f[temp2]<0){
		cont++;
	}
	if(cont>1){
		ok=false;
	}

if(ok){
	int ans=1;
	if(us[temp]==true)
	ans--;
	//cout<<ans<<endl;
	int comp=0;
	int indice=-1;
	for(int i=1;i<=n;i++){
		if(us[v[i-1]]==false){
			//cout<<i-1<<" "<<v[i-1]<<endl;
		v[i-1]=temp;
		
		indice=i-1;
		}
		if(ds[v[i-1]]==0)
		ds[v[i-1]]=v[i-1]+1;
		
		if(v[i-1]!=v1[i-1]&&us2[v[i-1]]==false){
			us2[v[i-1]]=true;
			comp++;
		}
		if(v[i-1]!=v1[i-1])
		ans++;	
	}
	if(indice!=-1&&us2[v[indice]]==false){
	comp++;
	ans++;
	}
	
	//cout<<comp<<" "<<ans<<endl;
	if(comp==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(find(v[i])!=find(v1[i])){
			add(v[i],v1[i]);
			comp--;
		}
	}
	ans+=comp-1;
	
	cout<<ans<<endl;
	
}
else
cout<<-1<<endl;

return 0;
}
