#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	
	vector <int> cnt(n, 0), cntb(n, 0), a(n), b(n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		a[i]--;
		
		cnt[a[i]]++;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		b[i]--;
		
		cnt[b[i]]++;
		cntb[b[i]]++;
	}
	
	set < pair <int, int> > s;
	for(int i = 0; i < n; i++){
		if(cnt[i] > n){
			printf("No\n");
			return 0;
		}
		if(cntb[i] > 0)s.insert(make_pair(cnt[i], i));
	}
	
	auto dec = [&](int x, int db){
	                cntb[x] -= db;
                    if(cntb[x] == 0){
                        if(db > 0)s.erase(make_pair(cnt[x], x));
                    }else{
                        auto d = s.extract(make_pair(cnt[x], x));
                        d.value().first--;
                        cnt[x]--;
                        s.insert(move(d));
                    }
	            };
	
	printf("Yes\n");
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		
		if(s.size() == 1){
			printf("%d", s.begin()->second + 1);
			continue;
		}
		
		int x = prev(s.end())->second, y = prev(prev(s.end()))->second;
		
		if(x != a[i]){
			printf("%d", x + 1);
			
			dec(a[i], 0);
			dec(x, 1);
		}else{
			printf("%d", y + 1);
			
		    dec(a[i], 0);
		    dec(y, 1);
		}
	}
	printf("\n");
	
	return 0;
}
