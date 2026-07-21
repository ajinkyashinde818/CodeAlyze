#include<stdio.h>

typedef long long int ll;

int main(void){
    int M, N;
    int a[100000];
    int br[100000];
    int i = 0;
    int j = 0;
    ll ans = 1;
    ll div=1000000007;
    ll st[100001];

	for(i = 0; i < 100000; i++){
    	a[i] = 0;
    }

  
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; i++){
        scanf("%d", &a[i]);
        if(i != 0 && a[i-1]+1 == a[i]){
            printf("0");
            return 0;
        }
    }

    br[0] = 0;

    for(i = 1; i <= N; i++){
        if(i == a[j]){
            br[i] = 1;
          	j++;
        }else{
            br[i] = 0;
        }
    }

    st[0] = 1;
    if(br[1] == 0){
        st[1] = 1;
    }else{
        st[2] = 2;
    }

    for(i = 2; i <= N; i++){
        if(br[i] == 0){
            if(br[i-1] == 0 && br[i-2] == 0){
                st[i] = st[i-1] + st[i-2];
            }else if(br[i-1] == 1){
                st[i] = st[i-2];
            }else if(br[i-2] == 1){
                st[i] = st[i-1];
            }
          	st[i] = st[i]%div;
            ans = st[i];
        }
    }


    printf("%lld", ans);
    return 0;
}
