/////////////////////////////////
//                             //
//           /(.^.)\           //
//                             //
/////////////////////////////////

#include <stdio.h>

#define LL long long
#define SD(x) scanf("%d", &(x))

//modは素数
const int mod = 1000000007;
const int N   = 100001;

//n!
int fact[N], invfact[N];

//a+b
inline int add(int a, int b)
{
    a += b;
    if(a >= mod) a -= mod;
    return a;
}

//a-b
inline int sub(int a, int b)
{
    a -= b;
    if(a < 0) a += mod;
    return a;
}

//a*b
inline int mul(int a, int b)
{
    return (((LL) a) * b) % mod;
}

//a^bのかっこいいやつ
inline int pwr(int a, LL b)
{
	int x = 1;
	while(b)
    {
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}

//なんか(m-2)乗したら逆数になるやつ
inline int inv(int a)
{
    return pwr(a, mod - 2);
}

//nCk求めるやつ改
inline int cmbxy(int x, int y)
{
	return mul(fact[x+y], mul(invfact[x], invfact[y]));
}

//n!求めるやつ
void calc_fact()
{
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	
    return;
}



int main()
{
    int n,m;
    int a, aa;
    int retn = 1;

    int x,y;
    int tmp;

    calc_fact();

    SD(n);
    SD(m);

    aa = -1;
    for (int i = 0; i <= m; ++i)
    {
        if (i == m)
        {
            a = n + 1;
        }
        else
        {
            SD(a);
        }

        if (aa == n-1)
        {
            break;
        }

        if (a - aa == 0)
        {
            continue;
        }
        else if ((a - aa == 1))
        {
            retn = 0;
            break;
        }
        else if (a - aa == 2)
        {

        }
        else
        {
            tmp = 0;
            for (x = a - aa - 2, y = 0; x >= 0; x -= 2, ++y)
            {
                tmp += cmbxy(x,y);
                if(tmp >= mod) tmp -= mod;

                /////////////////////
                //printf("%d %d %d\n" ,x,y,tmp);
            }
            retn = (((LL) retn) * tmp) % mod;
        }

        aa = a;
    }
   

    printf("%d" ,retn);

    return 0;
}
