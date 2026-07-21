#include<iostream>
#include<cmath>
using namespace std;

int main(){
	/*double*/unsigned long long int N;
	cin >> N;
	unsigned long long int i;
	char s[N];
	for(i=0; i<N; i++){
		cin >> s[i];
	}
	
	unsigned long long int count[26]={0}, Num=1;
	count[0]=1;
	char chars[26];
	chars[0]=s[0];
	
	unsigned long long int j=0;
	for(i=1; i<N; i++){
		int flg=0;
		j=0;
		do{
			if(s[i]==chars[j]){
				count[j]++;
				flg++;
			}
			else{
				j++;
			}
		}while(j<Num && flg==0);
		if(j==Num){
			count[j]=1;
			chars[j]=s[i];
			Num++;
		}
	}
	
	unsigned long long int ans = 1;
	for(i=0; i<Num; i++){
		ans *= (count[i]+1);
		if(ans>1000000007)	ans %= 1000000007;
	}
	ans %= 1000000007;
	
	cout << ans-1 << endl;
	
	return 0;
}
