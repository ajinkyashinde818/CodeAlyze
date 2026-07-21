#include<bits/stdc++.h>
using namespace std;

int main(){

  int N;

  cin>>N;

  long long a[100001];

  long long ans=0;

  long long cnt=0;

  cin>>a[0];

  
  if(a[0]<0){
	cnt++;
  }

  
  long long minn=labs(a[0]);
  
  ans+=labs(a[0]);
  
  for(int i=1;i<N;i++){
	cin>>a[i];

	if(a[i]<0){
	  cnt++;
	}

	if(minn>labs(a[i])){
	  minn=labs(a[i]);
	}

	ans+=(labs(a[i]));
	
  }
  
  
  if(cnt%2==0){
  }else{
	ans-=(2*labs(minn));

  }
  

  cout<<ans<<endl;
  
  return 0;
}
