/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑       永无BUG
*/
#include<stdio.h>
#define re register
long long a[100005],sum;
int main()
{
	int n;
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	long long all=1LL*n*(n+1)/2;
	if(sum%all!=0)
	{
		printf("NO");
		return 0;
	}
	long long k=sum/all;
	long long cnt=k;
	for(re int i=2;i<=n;++i)
	{
		if(a[i]-a[i-1]==k) continue;
		long long t=k-(a[i]-a[i-1]);
		if(t%n!=0||t<0)
		{
			printf("NO");
			return 0;
		}
		cnt-=t/n;
		if(cnt<0)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
